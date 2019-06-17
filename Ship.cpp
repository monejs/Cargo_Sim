#include "Ship.h"

#define cal(x) section_G[x]*section_vol[x]  //Definition for calculating the LCG of hull for particular draft

#define calL(x) section_LCG[x]*section_vol[x]

#define PI 3.14159265

#define cot(x) cos(x)/sin(x)


//Declares the possible types of units a user can make
const std::string Ship::u_type_strings[8] = {"Ballast", "Cargo Tank", "Cargo Hold", "HFO", "DO", "LO", "FW", "Various"};

void Ship::shipSize()
{
    sectionlength = s_LOA/10; // Divides the length of the ship into 10 compartments
    section_beam = {0.23f*s_beam, 0.6f*s_beam, s_beam, s_beam, s_beam, s_beam, s_beam, 0.75f*s_beam, 0.5f*s_beam, 0.25f*s_beam}; // The breadth of each compartment
    section_height = {0.9f*s_height, s_height, s_height, s_height, s_height, s_height, s_height, 0.8f*s_height, 0.5f*s_height, 0.3f*s_height};
}

// Function to check, if the input from user is valid and returns false, if not
bool Ship::assign_val(std::string& in_t, float& var)
{
    if (::atof(in_t.c_str()))
    {
        var = ::atof(in_t.c_str());
        return true;
    }else{ return false; }
}

// TODO: TCP, KMT, VHM
void Ship::calculate()
{

    HydroVec.clear();
    shipSize();
    int i=0;
//    std::cout << s_minDraft << s_maxDraft << std::endl;
     //The height of each compartment
    for (float draft=s_minDraft; draft<s_maxDraft+0.1; draft+=0.1f)
    {

        Hydrostatistics stats; // Makes a new class object for the stats to push back at end of the Hydrostatic vector
        stats.h_draft = draft; // Assigns a draft

        float hull_B=0;
        float hull_F=0, hull_BMl_vol=0, hull_BMl=0, hull_KM_vol=0;
        hull_KM=0;
        hull_LCG=0;
        hull_VCG=0;
        hull_BM=0;
        float floating_area=0;
        for (int section=0; section!=10; section++)
        {
            if (s_height - section_height[section] < draft)
            {
                section_area[section]=section_beam[section]*(draft-s_height+section_height[section]); // A_sec = Beam_sec * draft
                floating_area+=sectionlength *section_beam[section];
                section_vol[section]=sectionlength*section_beam[section]*(draft-s_height+section_height[section]); // Area * section length
                section_LCG[section]=section * sectionlength + sectionlength/2; //n*section + 1/2 section length
                section_G[section]=s_height-section_height[section]/2; // Maximum draft - section draft /2
                stats.h_volume += section_vol[section]; // Total underwater volume

                section_B[section]=(draft-s_height+section_height[section])/2 +s_height-section_height[section];
                hull_B+=section_B[section]*section_vol[section];
                hull_F+=section_LCG[section]*sectionlength*section_beam[section];
                section_BM[section]=(sectionlength*pow(section_beam[section],3))/(12*section_vol[section]);
                section_KM[section]=section_B[section]+section_BM[section];
                section_BMl[section]=(section_beam[section]*pow(sectionlength,3)*1.025)/(sectionlength);
                hull_BMl_vol+=section_BMl[section]*section_vol[section];
                hull_KM_vol+=section_KM[section]*section_vol[section];
 //               std::cout << section_KM[section] << std::endl;
            }else{

            }
        }

        hull_VCG=(cal(0)+cal(1)+cal(2)+cal(3)+cal(4)+cal(5)+cal(6)+cal(7)+cal(8)+cal(9))/stats.h_volume;
        hull_LCG=(calL(0)+calL(1)+calL(2)+calL(3)+calL(4)+calL(5)+calL(6)+calL(7)+calL(8)+calL(9))/stats.h_volume;
//      stats.h_lcb=hull_B/stats.h_volume;
        stats.h_lcf=hull_F/floating_area;
        stats.h_mct=hull_BMl_vol/stats.h_volume;
//      stats.h_mct=hull_BMl*1.025/s_LOA;
//      std::cout << std::endl;
        i++;
        stats.h_weight = stats.h_volume * s_waterCondition;
        if (HydroVec.size()>0) HydroVec[HydroVec.size()-1].h_tpc=(stats.h_weight-HydroVec[HydroVec.size()-1].h_weight)/10;
        stats.h_lcb=hull_LCG;
        stats.h_kmt=hull_KM_vol/stats.h_volume;

        HydroVec.push_back(stats);
    }
    std::cout << "Calculations done" << std::endl;
}

// Calculates the ships particulars automagicly, if so wished. This function is available over the particulars input mask.
/*void Ship::autoParticulars()
{
    float xmax = 0, ymax = 0, zmax = 0; // The maximum values of a unit
    for (long unsigned int i=0; i<UnitVec.size(); i++) // Iterates through all declared units
    { // and compares them. If a bigger number is found, the max value is replaced
        if(xmax < UnitVec[i].u_LCG + UnitVec[i].u_length) xmax = UnitVec[i].u_LCG + UnitVec[i].u_length;
        if(ymax < UnitVec[i].u_TCG + UnitVec[i].u_breadth) ymax = UnitVec[i].u_TCG + UnitVec[i].u_breadth;
        if(zmax < UnitVec[i].u_VCG + UnitVec[i].u_height) zmax = UnitVec[i].u_VCG + UnitVec[i].u_height;
    }
    // And here is the automagic
    s_LOA = xmax+10;
    s_beam = ymax+0.1f;
    s_height = zmax+0.5f;

    Ship::calculate();
}*/   //Maybe later on this one


void Ship::text_print(){
    std::string filename = s_name + " Hydrostatics.txt";
    std::ofstream out(filename,  std::ofstream::out | std::ofstream::trunc);

    out << std::setw(20) << "Ship Name"<<std::setw(5) << ":"<<std::setw(15)<< s_name << std::endl;
    out << std::setw(20) << "LOA"<<std::setw(5) << ":"<<std::setw(15)<< s_LOA << std::endl;
    out << std::setw(20) << "Beam"<<std::setw(5) << ":"<<std::setw(15)<< s_beam << std::endl;
    out << std::setw(20) << "Height"<<std::setw(5) << ":"<<std::setw(15) <<s_height << std::endl;
    out << std::setw(20) << "Dead Weight"<<std::setw(5) << ":"<<std::setw(15)<< s_maxDWT << std::endl;
    out << std::setw(20) << "Minimal draft"<<std::setw(5) << ":"<<std::setw(15)<< s_minDraft << std::endl;
    out << std::setw(20) << "Maximal draft"<<std::setw(5) << ":"<<std::setw(15) << s_maxDraft << std::endl;
    out << std::endl << std::endl;
    std::string dummy (89,'-');
    out << dummy<<std::endl;
    out <<" |" << std::setw(5) << "Draft"
    <<" |" << std::setw(10) << "Volume"
    <<" |" << std::setw(10) << "Displ"
    <<" |" << std::setw(7) << "TPC"
    <<" |" << std::setw(10) << "MCT"
    <<" |" << std::setw(7) << "KMT"
    <<" |" << std::setw(7) << "LCF"
    <<" |" << std::setw(7) << "LCB"
    <<" |" << std::setw(7) << "Draft |"<<std::endl << dummy << std::endl;

    for (int i=0; i<HydroVec.size(); i++)
    {
    out <<" |" << std::setw(5) << std::setprecision(2) << std::fixed << HydroVec[i].h_draft
        <<" |" << std::setw(10) << std::setprecision(0) << std::fixed << HydroVec[i].h_volume
        <<" |" << std::setw(10) << std::setprecision(0) << std::fixed << HydroVec[i].h_weight
        <<" |" << std::setw(7) << std::setprecision(2) << std::fixed << HydroVec[i].h_tpc
        <<" |" << std::setw(10) << std::setprecision(2) << std::fixed << HydroVec[i].h_mct
        <<" |" << std::setw(7) << std::setprecision(2) << std::fixed << HydroVec[i].h_kmt
        <<" |" << std::setw(7) << std::setprecision(2) << std::fixed << HydroVec[i].h_lcf
        <<" |" << std::setw(7) << std::setprecision(2)  << std::fixed <<  HydroVec[i].h_lcb
        <<" |" << std::setw(5) << std::setprecision(2) << std::fixed << HydroVec[i].h_draft << " |" <<std::endl;
        if ((i+1)%5==0)out<<dummy<<std::endl;
    }
    out << dummy << std::endl;

    out << std::endl << std::endl << std::endl;
    std::string dummy2 (89,'#');
    out << dummy2 << std::endl;
    out << std::setw(15) << "Compartments" << std::endl;
    out << dummy2 << std::endl;
    std::vector<int> carg;
    std::vector<int> bal;
    std::vector<int> hf;
    std::vector<int> md;
    std::vector<int> fw;
    std::vector<int> va;
    std::vector<int> lo;

    for (long unsigned int i=0; i<UnitVec.size(); i++)
    {
        if (UnitVec[i].u_type == u_types::Ballast) bal.push_back(i);
        if (UnitVec[i].u_type == u_types::Cargo_Tank) carg.push_back(i);
        if (UnitVec[i].u_type == u_types::Cargo_Hold) carg.insert(carg.begin(),i);
        if (UnitVec[i].u_type == u_types::HFO) hf.push_back(i);
        if (UnitVec[i].u_type == u_types::DO) md.push_back(i);
        if (UnitVec[i].u_type == u_types::LO) lo.push_back(i);
        if (UnitVec[i].u_type == u_types::FW) fw.push_back(i);
        if (UnitVec[i].u_type == u_types::Various) va.push_back(i);
    }

        std::string dummy3 (72, '-');
    if (carg.size()>0){ out << std::setw(15) << "Cargo" << std::endl << std::endl << dummy3 <<std::endl
        << " |" << std::setw(12) << "Name"
        << " |" << std::setw(7) << "LCG"
        << " |" << std::setw(7) << "TCG"
        << " |" << std::setw(7) << "VCG"
        << " |" << std::setw(7) << "Density"
        << " |" << std::setw(10) << "Volume"
        << " |" << std::setw(5) << "FSM" << std::endl << dummy3 << std::endl;
    for (long unsigned int i=0; i<carg.size(); i++)
    {
        out << " |" << std::setw(12) << UnitVec[carg[i]].u_name
            << " |" << std::setw(7) << std::setprecision(2) << std::fixed << UnitVec[carg[i]].u_LCG
            << " |" << std::setw(7) << std::setprecision(2) << std::fixed << UnitVec[carg[i]].u_TCG
            << " |" << std::setw(7) << std::setprecision(2) << std::fixed << UnitVec[carg[i]].u_VCG
            << " |" << std::setw(7) << std::setprecision(2) << std::fixed << UnitVec[carg[i]].u_density
            << " |" << std::setw(10) << std::setprecision(2) << std::fixed << UnitVec[carg[i]].u_volume
            << " |" << std::setw(5) << std::setprecision(2) << std::fixed << UnitVec[carg[i]].u_fsm << " |" <<std::endl;
            if ((i+1)%5==0)out<<dummy3<<std::endl;
    } out << std::endl << std::endl;
    }
    if (bal.size()>0){ out << std::setw(15) << "Ballast" << std::endl << std::endl << dummy3 <<std::endl
        << " |" << std::setw(12) << "Name"
        << " |" << std::setw(7) << "LCG"
        << " |" << std::setw(7) << "TCG"
        << " |" << std::setw(7) << "VCG"
        << " |" << std::setw(7) << "Density"
        << " |" << std::setw(10) << "Volume"
        << " |" << std::setw(5) << "FSM" << std::endl << dummy3 << std::endl;
    for (long unsigned int i=0; i<bal.size(); i++)
    {
        out << " |" << std::setw(12) << UnitVec[bal[i]].u_name
            << " |" << std::setw(7) << std::setprecision(2) << std::fixed << UnitVec[bal[i]].u_LCG
            << " |" << std::setw(7) << std::setprecision(2) << std::fixed << UnitVec[bal[i]].u_TCG
            << " |" << std::setw(7) << std::setprecision(2) << std::fixed << UnitVec[bal[i]].u_VCG
            << " |" << std::setw(7) << std::setprecision(2) << std::fixed << UnitVec[bal[i]].u_density
            << " |" << std::setw(10) << std::setprecision(2) << std::fixed << UnitVec[bal[i]].u_volume
            << " |" << std::setw(5) << std::setprecision(2) << std::fixed << UnitVec[bal[i]].u_fsm << " |" <<std::endl;
            if ((i+1)%5==0)out<<dummy3<<std::endl;
    }out << std::endl << std::endl;
    }

    if (hf.size()>0){ out << std::setw(15) << "HFO" << std::endl << std::endl << dummy3 <<std::endl
        << " |" << std::setw(12) << "Name"
        << " |" << std::setw(7) << "LCG"
        << " |" << std::setw(7) << "TCG"
        << " |" << std::setw(7) << "VCG"
        << " |" << std::setw(7) << "Density"
        << " |" << std::setw(10) << "Volume"
        << " |" << std::setw(5) << "FSM" << std::endl << dummy3 << std::endl;
    for (long unsigned int i=0; i<hf.size(); i++)
    {
        out << " |" << std::setw(12) << UnitVec[hf[i]].u_name
            << " |" << std::setw(7) << std::setprecision(2) << std::fixed << UnitVec[hf[i]].u_LCG
            << " |" << std::setw(7) << std::setprecision(2) << std::fixed << UnitVec[hf[i]].u_TCG
            << " |" << std::setw(7) << std::setprecision(2) << std::fixed << UnitVec[hf[i]].u_VCG
            << " |" << std::setw(7) << std::setprecision(2) << std::fixed << UnitVec[hf[i]].u_density
            << " |" << std::setw(10) << std::setprecision(2) << std::fixed << UnitVec[hf[i]].u_volume
            << " |" << std::setw(5) << std::setprecision(2) << std::fixed << UnitVec[hf[i]].u_fsm << " |" <<std::endl;
            if ((i+1)%5==0)out<<dummy3<<std::endl;
    }out << std::endl << std::endl;
    }
    if (md.size()>0){ out << std::setw(15) << "DO" << std::endl << std::endl << dummy3 <<std::endl
        << " |" << std::setw(12) << "Name"
        << " |" << std::setw(7) << "LCG"
        << " |" << std::setw(7) << "TCG"
        << " |" << std::setw(7) << "VCG"
        << " |" << std::setw(7) << "Density"
        << " |" << std::setw(10) << "Volume"
        << " |" << std::setw(5) << "FSM" << std::endl << dummy3 << std::endl;
    for (long unsigned int i=0; i<md.size(); i++)
    {
        out << " |" << std::setw(12) << UnitVec[md[i]].u_name
            << " |" << std::setw(7) << std::setprecision(2) << std::fixed << UnitVec[md[i]].u_LCG
            << " |" << std::setw(7) << std::setprecision(2) << std::fixed << UnitVec[md[i]].u_TCG
            << " |" << std::setw(7) << std::setprecision(2) << std::fixed << UnitVec[md[i]].u_VCG
            << " |" << std::setw(7) << std::setprecision(2) << std::fixed << UnitVec[md[i]].u_density
            << " |" << std::setw(10) << std::setprecision(2) << std::fixed << UnitVec[md[i]].u_volume
            << " |" << std::setw(5) << std::setprecision(2) << std::fixed << UnitVec[md[i]].u_fsm << " |" <<std::endl;
            if ((i+1)%5==0)out<<dummy3<<std::endl;
    }out << std::endl << std::endl;
    }
    if (fw.size()>0){ out << std::setw(15) << "Fresh Water" << std::endl << std::endl << dummy3 <<std::endl
        << " |" << std::setw(12) << "Name"
        << " |" << std::setw(7) << "LCG"
        << " |" << std::setw(7) << "TCG"
        << " |" << std::setw(7) << "VCG"
        << " |" << std::setw(7) << "Density"
        << " |" << std::setw(10) << "Volume"
        << " |" << std::setw(5) << "FSM" << std::endl << dummy3 << std::endl;
    for (long unsigned int i=0; i<fw.size(); i++)
    {
        out << " |" << std::setw(12) << UnitVec[fw[i]].u_name
            << " |" << std::setw(7) << std::setprecision(2) << std::fixed << UnitVec[fw[i]].u_LCG
            << " |" << std::setw(7) << std::setprecision(2) << std::fixed << UnitVec[fw[i]].u_TCG
            << " |" << std::setw(7) << std::setprecision(2) << std::fixed << UnitVec[fw[i]].u_VCG
            << " |" << std::setw(7) << std::setprecision(2) << std::fixed << UnitVec[fw[i]].u_density
            << " |" << std::setw(10) << std::setprecision(2) << std::fixed << UnitVec[fw[i]].u_volume
            << " |" << std::setw(5) << std::setprecision(2) << std::fixed << UnitVec[fw[i]].u_fsm << " |" <<std::endl;
            if ((i+1)%5==0)out<<dummy3<<std::endl;
    }out << std::endl << std::endl;
    }
    if (lo.size()>0){ out << std::setw(15) << "Lube Oil" << std::endl << std::endl << dummy3 <<std::endl
        << " |" << std::setw(12) << "Name"
        << " |" << std::setw(7) << "LCG"
        << " |" << std::setw(7) << "TCG"
        << " |" << std::setw(7) << "VCG"
        << " |" << std::setw(7) << "Density"
        << " |" << std::setw(10) << "Volume"
        << " |" << std::setw(5) << "FSM" << std::endl << dummy3 << std::endl;
    for (long unsigned int i=0; i<lo.size(); i++)
    {
        out << " |" << std::setw(12) << UnitVec[lo[i]].u_name
            << " |" << std::setw(7) << std::setprecision(2) << std::fixed << UnitVec[lo[i]].u_LCG
            << " |" << std::setw(7) << std::setprecision(2) << std::fixed << UnitVec[lo[i]].u_TCG
            << " |" << std::setw(7) << std::setprecision(2) << std::fixed << UnitVec[lo[i]].u_VCG
            << " |" << std::setw(7) << std::setprecision(2) << std::fixed << UnitVec[lo[i]].u_density
            << " |" << std::setw(10) << std::setprecision(2) << std::fixed << UnitVec[lo[i]].u_volume
            << " |" << std::setw(5) << std::setprecision(2) << std::fixed << UnitVec[lo[i]].u_fsm << " |" <<std::endl;
            if ((i+1)%5==0)out<<dummy3<<std::endl;
    }out << std::endl << std::endl;
    }
    if (va.size()>0){ out << std::setw(15) << "Various" << std::endl << std::endl << dummy3 <<std::endl
        << " |" << std::setw(12) << "Name"
        << " |" << std::setw(7) << "LCG"
        << " |" << std::setw(7) << "TCG"
        << " |" << std::setw(7) << "VCG"
        << " |" << std::setw(7) << "Density"
        << " |" << std::setw(10) << "Volume"
        << " |" << std::setw(5) << "FSM" << std::endl << dummy3 << std::endl;
    for (long unsigned int i=0; i<va.size(); i++)
    {
        out << " |" << std::setw(12) << UnitVec[va[i]].u_name
            << " |" << std::setw(7) << std::setprecision(2) << std::fixed << UnitVec[va[i]].u_LCG
            << " |" << std::setw(7) << std::setprecision(2) << std::fixed << UnitVec[va[i]].u_TCG
            << " |" << std::setw(7) << std::setprecision(2) << std::fixed << UnitVec[va[i]].u_VCG
            << " |" << std::setw(7) << std::setprecision(2) << std::fixed << UnitVec[va[i]].u_density
            << " |" << std::setw(10) << std::setprecision(2) << std::fixed << UnitVec[va[i]].u_volume
            << " |" << std::setw(5) << std::setprecision(2) << std::fixed << UnitVec[va[i]].u_fsm << " |" <<std::endl;
            if ((i+1)%5==0)out<<dummy3<<std::endl;
    }}

    out.close();
}

// This is the model, which will be used to make the data for the ship.
// TODO: Make the model variable
/* void Ship::modelLoad()
{
    std::ifstream file;             // Declares where the model file is with its point coordinates.
    file.open("Model.txt", std::ios_base::in); // Opens file
    if (file.is_open())             // If file found, read the coordinates
    {
        int i=0;                    // For the point vector
        for (std::string line; std::getline(file, line); ) // Reads the text file line for line
        {
            points.push_back(std::vector<float>()); // Adds a vector to the vector (It's a 2D vector)
            points[i].push_back(3);                 // Pushing back 3 spaces in the vector for x, y and z
            std::istringstream in(line);            // Turns the read line into a stream for easier conversion.
            in >> points[i][0] >> points[i][1] >> points[i][2]; // Converts the string stream into floating points
            i++;                                    // Next section for the floating point vector
        }
    }
    file.close(); // When all done, close file.
    std::stable_sort(points.begin(), points.end());       // Sorts the vector according to x
    rib dumdum;                                     // A dummy to add on the ribs vector
    // The vector ribs consists of a class rib. This class contains a single float for the x coordinate and a float vector for the zy coordinates
    // This provides the ribs of the ship
    ribs.push_back(dumdum);                         // Adding the dummy
    int j=0, l=0;                                   // Iteration help for the vectors
    / Iterate through all points starting with x = 0 through the length of model ship
    and getting all the point in a single rib /
    for (long unsigned int i=0; i<points.size(); i++)
    {
        if (i+1 != points.size()){ // Checking if there is a next vector float
            ribs[j].x=points[i][0]; // Sets the x so it is known later for math
            ribs[j].zy.push_back(std::vector<float>()); // Adds a new object of vector to the zy vector in ribs class.
            ribs[j].zy[l].push_back(2); // Adds two places in the vector for the z and y coordinates
            // z and y coordinates are assigned for the starboard side of the ship and also the port side coordinates are created
            // z axis is from keel up, y axis is from keel line to starboard
            ribs[j].zy[l][0] = points[i][2];
            ribs[j].zy[l][1] = points[i][1];
            l++;
            ribs[j].zy.push_back(std::vector<float>());
            ribs[j].zy[l].push_back(2);
            ribs[j].zy[l][0] = points[i][2];
            ribs[j].zy[l][1] = - points[i][1];
            l++;
            if (points[i][0] != points[i+1][0]) // If the next x is different, then go to next iteration of the rib vector
            {
                l=0; // For the ribs inner vector
                j++; // For the ribs vector
                rib dummy; // New element in the ribs vector
                ribs.push_back(dummy);
            }
        }else{ // All the same as above, only in case this is the last element
            ribs[j].x=points[i][0];
            ribs[j].zy.push_back(std::vector<float>());
            ribs[j].zy[l].push_back(2);
            ribs[j].zy[l][0] = points[i][2];
            ribs[j].zy[l][1] = points[i][1];
            l++;
            ribs[j].zy.push_back(std::vector<float>());
            ribs[j].zy[l].push_back(2);
            ribs[j].zy[l][0] = points[i][2];
            ribs[j].zy[l][1] = - points[i][1];
        }
    }
    // This will go through all the ribs and sort the z values from keel to deck, thus making the math afterwards easier
    for (long unsigned int i=0; i<ribs.size(); i++)
    {
        std::stable_sort(ribs[i].zy.begin(), ribs[i].zy.end());
    }
}*/

float Ship::find_draft(float dsp)
{

    std::array<float, 10> sumhb; // This will be the sums for the equation, to set the draft
    shipSize();
    float draft, sumb=0;
    for (int i=0; i!=10; i++)
    {
        sumb+=section_beam[i];
        sumhb[i]=section_beam[i]*s_height-section_beam[i]*section_height[i];
    }
//    std::cout << dsp << "  " << sumb << "  " << s_waterCondition << std::endl;
    draft=(((dsp/sectionlength)-sumhb[0]-sumhb[1]-sumhb[2]-sumhb[3]-sumhb[4]-sumhb[5]-sumhb[6]-sumhb[7]-sumhb[8]-sumhb[9]))/(sumb);
    return draft;
}



float Ship::stabi(int heel)
{
    hull_KM=0;
    hull_VCG=0;
    float draft = find_draft(disp());
    float beta=0, gamma=0, areaS=0, perS=0, ha=0, c=0, d=0, g=0, k=0, j=0,m=0, n=0, o=0, p=0, s=0, b1=0, a1=0, y=0, z=0, Nc=0, kn;
    float gz=0;
    float hull_B=0;
    float hull_F=0;
    float floating_area=0;
    hull_BM=0;
    s_volume=0;
    for (int section=0; section!=10; section++)
    {
        if (s_height - section_height[section] < draft)
        {
            section_area[section]=section_beam[section]*(draft-s_height+section_height[section]); // A_sec = Beam_sec * draft
            floating_area+=sectionlength *section_beam[section];
            section_vol[section]=section_area[section]*sectionlength; // Area * section length
            section_LCG[section]=section * sectionlength + sectionlength/2; //n*section + 1/2 section length
            section_G[section]=s_height-section_height[section]/2; // Maximum draft - section draft /2
            s_volume += section_vol[section]; // Total underwater volume


            section_B[section]=(draft-s_height+section_height[section])/2 +s_height-section_height[section];
            hull_B+=section_B[section]*section_vol[section];
            hull_F+=section_LCG[section]*sectionlength*section_beam[section];
            section_BM[section]=(sectionlength*pow(section_beam[section],3))/(12*section_vol[section]);
            section_KM[section]=section_B[section]+section_BM[section];
            hull_BM+=section_BM[section]*section_vol[section];
            hull_KM+=section_KM[section]*section_vol[section];
            hull_VCG+=section_G[section]*section_vol[section];
            hull_LCG+=section_LCG[section]*section_vol[section];
 //           std::cout << section << ".: " << sectionlength << "  " << section_beam[section] << "  " << " " << section_B[section] << "  " << section_BM[section] << "  "<< section_KM[section] << "  " << section_vol[section] << std::endl;
        }
    }
//    std::cout << draft << "  " << heel << std::endl;
    s_VCG = disp_vcg();
    s_bm = hull_BM/s_volume;
    s_km = hull_KM/s_volume;
    s_gm = s_km-s_VCG;

    c=s_beam/(2*cot(heel*PI/180));

    beta=90-heel;
    gamma=90-beta;

    if(c<draft)
    {
        b1=draft-c;
        a1=draft+c;
        y=(s_beam*(b1+2*a1))/(3*(a1+b1));
        z=(pow(a1,2)+a1*b1+pow(b1,2))/(3*(a1+b1));
        k=b1-z;
        j=sqrt(pow(s_beam-y, 2)+pow(k, 2));

        m=c/sin(heel*PI/180);
        d=sqrt(pow(y-s_beam/2,2)+pow(draft-z, 2));
        p=(d+j+m)/2;
        areaS=sqrt(p*(p-d)*(p-m)*(p-j));
        ha=2*areaS/m;
        n=sqrt(pow(j,2)-pow(ha,2));
        o=m-n;
        s=o/cot(beta*PI/180);
        Nc=s/cos(gamma*PI/180);
        kn=draft+Nc;
        gz=kn*sin(heel*PI/180)-disp_vcg()*sin(heel*PI/180);
 //       std::cout << heel << ".:  a1:" << a1 << "  b1:" << b1 << "  y:" << y << "  z:" << z << "  g:" << g << "  k:" << k <<  "  j:" << j << "  c:" << c << "  m:" << m << "  d:" << d << "  p:" << p << "  Strij:" << areaS <<
 //    "  ha:" << ha << "  n:" << n << "  o:" << o << "  s:" << s << "  Nc:" << Nc << "  kn:" << kn << "  km:" << s_km << "  gz:" << gz << std::endl;
     if(isnan(gz))
     {
         return 0.0f;
     }
     return gz;
    }
    return 0.0f;


}

float Ship::gm()
{
    return s_gm;
}

float Ship::trim()
{
    float draft = find_draft(disp());
    float trim_moment;
    float hull_B;
    float hull_F;
    float lcb, lcf;
    float floating_area;
    for (int section=0; section!=10; section++)
    {
        if (s_height - section_height[section] < draft)
        {
            section_area[section]=section_beam[section]*(draft-s_height+section_height[section]); // A_sec = Beam_sec * draft
            floating_area+=sectionlength *section_beam[section];
            section_vol[section]=section_area[section]*sectionlength; // Area * section length
            section_LCG[section]=section * sectionlength + sectionlength/2; //n*section + 1/2 section length
            section_G[section]=s_height-section_height[section]/2; // Maximum draft - section draft /2
            s_volume += section_vol[section]; // Total underwater volume


            section_B[section]=(draft-s_height+section_height[section])/2 +s_height-section_height[section];
            hull_B+=section_B[section]*section_vol[section];
            hull_F+=section_LCG[section]*sectionlength*section_beam[section];
            section_BM[section]=(sectionlength*pow(section_B[section],3))/(12*section_vol[section]);
            section_KM[section]=section_B[section]+section_BM[section];

        }
    }
    hull_VCG=(cal(0)+cal(1)+cal(2)+cal(3)+cal(4)+cal(5)+cal(6)+cal(7)+cal(8)+cal(9))/s_volume;
    hull_LCG=(calL(0)+calL(1)+calL(2)+calL(3)+calL(4)+calL(5)+calL(6)+calL(7)+calL(8)+calL(9))/s_volume;
    lcb=hull_B/s_volume;
    lcf=hull_F/floating_area;
    trim_moment = (hull_LCG-lcb)*disp();
}

float Ship::init_heel()
{
    float A=0, b=0, a=0, c=0, d, alfa;
    A = find_draft(disp())*s_beam;
    b=(4*A/s_beam)-(6*A*(disp_tcg()+s_beam/2)/pow(s_beam, 2));
    a=2*A/s_beam -b;
    c=(a-b)/2;
    d=s_beam/2;
    alfa=atan(c/d)*57.3;

    std::cout << "A:" << A << "  a:" << a << "  b:" << b << "  alpha:" << alfa << std::endl;

    return alfa;
}

const std::string Ship::currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}
// Saves all the data to file using the google protobuf protocol.
// Quite easy to use and can be generates automatically.
bool Ship::save(std::string filename)
{
    /* Since the database provided by the protobuf is not meant to be worked with as a regular class,
    and the values have to be brought over to the buffer class for its operation*/
    // First it saves all ships body values
    ship::ShipBodyData SaveShip; // Makes a protobuf class object
    ship::ShipData* shipdata = SaveShip.add_shipdata(); // Adds a ship data class to the protobuf class object
    // Setting all the parameters
    shipdata->set_shipname(s_name);
    shipdata->set_loa(s_LOA);
    shipdata->set_beam(s_beam);
    shipdata->set_height(s_height);
    shipdata->set_lcglight(s_LCGLight);
    shipdata->set_tcglight(s_TCGLight);
    shipdata->set_vcglight(s_VCGLight);
    shipdata->set_lightship(s_lightShip);
    shipdata->set_mindraft(s_minDraft);
    shipdata->set_maxdraft(s_maxDraft);
    shipdata->set_maxdwt(s_maxDWT);
    shipdata->set_deckstr(s_strengthCover);
    shipdata->set_tankstr(s_strengthTank);
    shipdata->set_watercondition(s_waterCondition);
    // Here it iterates through all the unit, the user has provided and saves them to the class
    // The same is applicable to the rest of this function
    for (long unsigned int i=0; i < UnitVec.size(); i++)
    {
        ship::Unit* unit = SaveShip.add_unit();
        unit->set_name(UnitVec[i].u_name);
        if (UnitVec[i].u_type == u_types::Ballast) unit->set_type(ship::Unit::BALLAST);
        if (UnitVec[i].u_type == u_types::Cargo_Tank) unit->set_type(ship::Unit::CARGOTANK);
        if (UnitVec[i].u_type == u_types::Cargo_Hold) unit->set_type(ship::Unit::CARGODRY);
        if (UnitVec[i].u_type == u_types::HFO) unit->set_type(ship::Unit::HFO);
        if (UnitVec[i].u_type == u_types::DO) unit->set_type(ship::Unit::DO);
        if (UnitVec[i].u_type == u_types::LO) unit->set_type(ship::Unit::LO);
        if (UnitVec[i].u_type == u_types::FW) unit->set_type(ship::Unit::FW);
        if (UnitVec[i].u_type == u_types::Various) unit->set_type(ship::Unit::VA);
        unit->set_lcg(UnitVec[i].u_LCG);
        unit->set_tcg(UnitVec[i].u_TCG);
        unit->set_vcg(UnitVec[i].u_VCG);
        unit->set_length(UnitVec[i].u_length);
        unit->set_breadth(UnitVec[i].u_breadth);
        unit->set_height(UnitVec[i].u_height);
        unit->set_volume(UnitVec[i].u_weight);
        unit->set_density(UnitVec[i].u_density);
    }
    for (long unsigned int i=0; i<BulkVec.size(); i++)
    {
        ship::BulkCargo* cargo = SaveShip.add_bulk();
        cargo->set_name (BulkVec[i].u_name);
        cargo->set_lcg (BulkVec[i].u_LCG);
        cargo->set_tcg (BulkVec[i].u_TCG);
        cargo->set_vcg (BulkVec[i].u_VCG);
        cargo->set_length(BulkVec[i].u_length);
        cargo->set_breadth(BulkVec[i].u_breadth);
        cargo->set_height(BulkVec[i].u_height);
        cargo->set_weight(BulkVec[i].u_weight);
    }
    filename += ".ship"; // Program specific filename
    std::fstream output(filename,  std::ios::out | std::ios::trunc | std::ios::binary); // Creating file
    if (SaveShip.SerializeToOstream(&output)){
        output.close(); // File closed
        return true;

    }else {
        output.close(); // File closed
        return false; // Writing to file
    }
}

bool Ship::load(std::string file) // Load the protobuf file in the program.
{
    std::fstream input(file, std::ios::in | std::ios::binary); // The file name and path is provided by the UI
    ship::ShipBodyData BodyOfShip; // Declaring the protobuf class to read all the data into
    if (!BodyOfShip.ParseFromIstream(&input)) // Checking, if file is, what this program is made for
    {
        return false; // If not the statement false is returned and the loading is stopped.
    }else{
        // The same as saving, only reverse
        const ship::ShipData& body = BodyOfShip.shipdata(0);
        s_name = body.shipname();
        s_LOA = body.loa();
        s_beam = body.beam();
        s_height = body.height();
        s_strengthCover = body.deckstr();
        s_strengthTank = body.tankstr();
        s_minDraft = body.mindraft();
        s_maxDraft = body.maxdraft();
        s_lightShip = body.lightship();
        s_LCGLight = body.lcglight();
        s_VCGLight = body.vcglight();
        s_TCGLight = body.tcglight();
        s_waterCondition = body.watercondition();
        s_maxDWT = body.maxdwt();
 //       std::cout << "Read Ships particulats" << std::endl;
        for (int i=0; i<BodyOfShip.unit_size(); i++)
        {
            Unit unit;
            UnitVec.push_back(unit);
            const ship::Unit& unit1 = BodyOfShip.unit(i);
            UnitVec[i].u_name = unit1.name();
            UnitVec[i].u_LCG = unit1.lcg();
            UnitVec[i].u_TCG = unit1.tcg();
            UnitVec[i].u_VCG = unit1.vcg();
            UnitVec[i].u_length = unit1.length();
            UnitVec[i].u_breadth = unit1.breadth();
            UnitVec[i].u_height = unit1.height();
            UnitVec[i].u_weight = unit1.volume();
            UnitVec[i].u_density = unit1.density();
            switch (unit1.type())
            {
                case (ship::Unit::BALLAST):
                    UnitVec[i].u_type = u_types::Ballast;
                    break;
                case (ship::Unit::CARGODRY):
                    UnitVec[i].u_type = u_types::Cargo_Hold;
                    break;
                case (ship::Unit::CARGOTANK):
                    UnitVec[i].u_type = u_types::Cargo_Tank;
                    break;
                case (ship::Unit::HFO):
                    UnitVec[i].u_type = u_types::HFO;
                    break;
                case (ship::Unit::DO):
                    UnitVec[i].u_type = u_types::DO;
                    break;
                case (ship::Unit::LO):
                    UnitVec[i].u_type = u_types::LO;
                    break;
                case (ship::Unit::FW):
                    UnitVec[i].u_type = u_types::FW;
                    break;
                case (ship::Unit::VA):
                    UnitVec[i].u_type = u_types::Various;
                    break;
            }
//            std::cout << "Unit nr. " << i << std::endl;
        } // Unit Loop
        for (int i=0; i<BodyOfShip.bulk_size(); i++)
        {
            const ship::BulkCargo& cargo = BodyOfShip.bulk(i);
            BulkVec[i].u_name = cargo.name();
            BulkVec[i].u_LCG = cargo.lcg();
            BulkVec[i].u_TCG = cargo.tcg();
            BulkVec[i].u_VCG = cargo.vcg();
            BulkVec[i].u_length = cargo.length();
            BulkVec[i].u_breadth = cargo.breadth();
            BulkVec[i].u_height = cargo.height();
            BulkVec[i].u_weight = cargo.weight();
        }
        return true; // At the end returns true
    }
}


// A function to clear data after a reset or file load of a ship
void Ship::clear_data()
{
    Ship();
    UnitVec.clear();
}

Ship::Ship() // Declaration of the Ships null state.
{
    s_name = "Ship"; // Simple name with intention, it will be changed
    s_LOA = 100.0f;     // Same as the model ship for LOA, beam and height, min draft and max draft
    s_beam = 16.4f;
    s_height = 10.0f;
    s_lightShip = 5600;
    s_strengthTank = 20.0f;
    s_strengthCover = 5.0f;
    s_minDraft = 0.5f;
    s_maxDraft = 7.5f;
    s_maxDWT = 15000;
    s_waterCondition = 1.025;
    s_LCGLight = 40.0f;
    s_TCGLight = 0.0f;
    s_VCGLight = 7.5f;
}
// Setting ships particulars through function, since the values are not supposed to be accessed publicly.
// Also checks, if the input values are valid.
bool Ship::set_s_name(std::string in_t){
    if (in_t != "")
    {
        s_name = in_t;
        return true;
    }else{return false;}
}
// For all the floating points the function at the top of this class is used.
bool Ship::set_s_LOA(std::string in_t){
    return Ship::assign_val(in_t, s_LOA);
}
bool Ship::set_s_beam(std::string in_t){
    return Ship::assign_val(in_t, s_beam);
}
bool Ship::set_s_height(std::string in_t){
    return Ship::assign_val(in_t, s_height);
}
bool Ship::set_s_strengthTank(std::string in_t){
    return Ship::assign_val(in_t, s_strengthTank);
}
bool Ship::set_s_strengthCover(std::string in_t){
    return Ship::assign_val(in_t, s_strengthCover);
}
bool Ship::set_s_minDraft(){
    s_minDraft=find_draft(s_lightShip);

    return true;
}
bool Ship::set_s_maxDraft(std::string in_t){
    return Ship::assign_val(in_t, s_maxDraft);
}
bool Ship::set_s_maxDWT(){
    s_maxDWT=0;
    for (int i=0; i!=10; i++)
    {
        if (s_maxDraft>s_height-section_height[i])
        {
        s_maxDWT+=sectionlength*section_beam[i]*(s_maxDraft-(s_height-section_height[i]));
        }
    }
    return true;
}
bool Ship::set_s_lightShip(std::string in_t){
    if (atoi(in_t.c_str()))
    {
        s_lightShip = atoi(in_t.c_str());
        return true;
    }else{return false;}
}
bool Ship::set_s_LCGLight(std::string in_t){
    return Ship::assign_val(in_t, s_LCGLight);
}
bool Ship::set_s_TCGLight(std::string in_t){
    return Ship::assign_val(in_t, s_TCGLight);
}
bool Ship::set_s_VCGLight(std::string in_t){
    return Ship::assign_val(in_t, s_VCGLight);
}

void Ship::variable_update()
{
    for (long unsigned int i=0; i<UnitVec.size(); i++)
    {
        if (UnitVec[i].u_type == u_types::Ballast) UnitVec[i].u_density=1.025f;
        if (UnitVec[i].u_type == u_types::Cargo_Tank) UnitVec[i].u_density =1.0f;
        if (UnitVec[i].u_type == u_types::Cargo_Hold) UnitVec[i].u_density=1.0f;
        if (UnitVec[i].u_type == u_types::HFO) UnitVec[i].u_density=0.89f;
        if (UnitVec[i].u_type == u_types::DO) UnitVec[i].u_density=0.98f;
        if (UnitVec[i].u_type == u_types::LO) UnitVec[i].u_density=0.72;
        if (UnitVec[i].u_type == u_types::FW) UnitVec[i].u_density=1.0f;
        if (UnitVec[i].u_type == u_types::Various) UnitVec[i].u_density=1.0f;

    }
}

// These functions return references to the actual values, so nothing is copied over
std::string& Ship::read_s_name(){return s_name;}

float& Ship::read_s_LOA(){return s_LOA;}

float& Ship::read_s_beam(){return s_beam;}

float& Ship::read_s_height(){return s_height;}

float& Ship::read_s_strengthTank(){return s_strengthTank;}

float& Ship::read_s_strengthCover(){return s_strengthCover;}

float& Ship::read_s_minDraft(){return s_minDraft;}

float& Ship::read_s_maxDraft(){return s_maxDraft;}

float Ship::read_s_maxDWT(){return s_maxDWT;}

int& Ship::read_s_lightShip(){return s_lightShip;}

float& Ship::read_s_LCGLight(){return s_LCGLight;}

float& Ship::read_s_TCGLight(){return s_TCGLight;}

float& Ship::read_s_VCGLight(){return s_VCGLight;}

bool Ship::set_u_name(int row, std::string val){
    UnitVec[row].u_name = val;
    return true;
    }
bool Ship::set_u_type(int row, std::string val)
{
    if (val == u_type_strings[0]) UnitVec[row].u_type = u_types::Ballast;
    if (val == u_type_strings[1]) UnitVec[row].u_type = u_types::Cargo_Tank;
    if (val == u_type_strings[2]) UnitVec[row].u_type = u_types::Cargo_Hold;
    if (val == u_type_strings[3]) UnitVec[row].u_type = u_types::HFO;
    if (val == u_type_strings[4]) UnitVec[row].u_type = u_types::DO;
    if (val == u_type_strings[5]) UnitVec[row].u_type = u_types::LO;
    if (val == u_type_strings[6]) UnitVec[row].u_type = u_types::FW;
    if (val == u_type_strings[7]) UnitVec[row].u_type = u_types::Various;
    return true;
}
bool Ship::set_u_lcg(int row, std::string val){
    return Ship::assign_val(val, UnitVec[row].u_LCG);}

bool Ship::set_u_vcg(int row, std::string val){
    return Ship::assign_val(val, UnitVec[row].u_VCG);}
bool Ship::set_u_tcg(int row, std::string val){
    return Ship::assign_val(val, UnitVec[row].u_TCG);}
bool Ship::set_u_height (int row, std::string val){
    return Ship::assign_val(val, UnitVec[row].u_height);}
bool Ship::set_u_length (int row, std::string val){
    return Ship::assign_val(val, UnitVec[row].u_length);}
bool Ship::set_u_breadth (int row, std::string val){
    return Ship::assign_val(val, UnitVec[row].u_breadth);}

bool Ship::set_u_weight(int row, std::string val)
{
    if (::atof(val.c_str())/UnitVec[row].u_density <= Ship::read_u_maxvol(row))
        {
            return Ship::assign_val(val, UnitVec[row].u_weight);
        }else {return false;}
}

bool Ship::set_u_pvol(int row, std::string val)
{
    if (::atof(val.c_str())<=100)
    {
        UnitVec[row].u_weight=Ship::read_u_maxvol(row)*UnitVec[row].u_density*::atof(val.c_str())/100;
        return true;
    }else {return false;}
}

bool Ship::set_u_vol(int row, std::string val)
{
    if (::atof(val.c_str()) && ::atof(val.c_str())<=Ship::read_u_maxvol(row))
    {
        UnitVec[row].u_weight = ::atof(val.c_str())*UnitVec[row].u_density;
        return true;
    }else{return false;}
}

bool Ship::set_u_density(int row, std::string val)
{
    return Ship::assign_val(val, UnitVec[row].u_density);
    UnitVec[row].u_weight=Ship::read_u_pvol(row)*UnitVec[row].u_density;
}

// Returns the values of units
std::string& Ship::read_unit_name (int x){
    return UnitVec[x].u_name;}

std::string Ship::read_unit_type(int x){
    return u_type_strings[UnitVec[x].u_type];}

float& Ship::read_u_LCG(int x){ //Returns the values of particular units
    return UnitVec[x].u_LCG;}
float& Ship::read_u_VCG(int x){
    return UnitVec[x].u_VCG;}
float& Ship::read_u_TCG(int x){
    return UnitVec[x].u_TCG;}
float& Ship::read_u_weight(int x){
    return UnitVec[x].u_weight;}
float Ship::read_u_volume(int x){
    return UnitVec[x].u_weight/UnitVec[x].u_density;}

float& Ship::read_u_density(int x){
    return UnitVec[x].u_density;}

float& Ship::read_u_length(int x){
    return UnitVec[x].u_length;}
float& Ship::read_u_breadth(int x){
    return UnitVec[x].u_breadth;}
float& Ship::read_u_height(int x){
    return UnitVec[x].u_height;}

// The maximum volume is never saved, but always recalculated for more accuracy
float Ship::read_u_maxvol(int i){
return (UnitVec[i].u_length*UnitVec[i].u_breadth*UnitVec[i].u_height);}

float Ship::read_u_pvol(int i)
{
    return Ship::read_u_volume(i)*100/Ship::read_u_maxvol(i);
}

float Ship::read_u_fsmax(int x)
{
    return ((UnitVec[x].u_length*UnitVec[x].u_density*pow(UnitVec[x].u_breadth,3))/(12*disp()));
}

// For the input of constants of the ship. These values are things like paint store, personal belongings, provisions etc.
bool Ship::set_con_name(int row, std::string val)
{
    ConVec[row].con_name = val;
    return true;}
// All functions call the one function to test, if the input is in fact a number
bool Ship::set_con_lcg(int row, std::string val){
    return Ship::assign_val(val, ConVec[row].con_lcg);}

bool Ship::set_con_tcg(int row, std::string val){
    return Ship::assign_val(val, ConVec[row].con_tcg);}

bool Ship::set_con_vcg(int row, std::string val){
    return Ship::assign_val(val, ConVec[row].con_vcg);}

bool Ship::set_con_weight(int row, std::string val){
    return Ship::assign_val(val, ConVec[row].con_weight);}

bool Ship::set_con_start(int row, std::string val){
    return Ship::assign_val(val, ConVec[row].con_start);}

bool Ship::set_con_end(int row, std::string val){
    return Ship::assign_val(val, ConVec[row].con_end);}

float Ship::constants_weight()
{
    float weight=0;
    for (long unsigned int i=0; i<ConVec.size(); i++)
    {
        weight+=ConVec[i].con_weight;
    }
    return weight;
}

float Ship::constants_LCG()
{
    float weight=0, xweight=0;
    for (long unsigned int i=0; i<ConVec.size(); i++)
    {
        weight+=ConVec[i].con_weight;
        xweight+=ConVec[i].con_weight*ConVec[i].con_lcg;
    }
    if (weight == 0)
    {
        return 0;
    }else {
    return xweight/weight;
    }
}

float Ship::constants_VCG()
{
    float weight=0, xweight=0;
    for (long unsigned int i=0; i<ConVec.size(); i++)
    {
        weight+=ConVec[i].con_weight;
        xweight+=ConVec[i].con_weight*ConVec[i].con_vcg;
    }
    if (weight == 0)
    {
        return 0;
    }else {
    return xweight/weight;
    }
}

float Ship::constants_TCG()
{
    float weight=0, xweight=0;
    for (long unsigned int i=0; i<ConVec.size(); i++)
    {
        weight+=ConVec[i].con_weight;
        xweight+=ConVec[i].con_weight*ConVec[i].con_tcg;
    }
    if (weight == 0)
    {
        return 0;
    }else {
    return xweight/weight;
    }
}

float Ship::unit_weight()
{
    float weight=0;
    for (long unsigned int i=0; i<UnitVec.size(); i++)
    {
        weight+=UnitVec[i].u_weight;
    }
    return weight;
}

float Ship::unit_LCG()
{
    float weight=0, xweight=0;
    for (long unsigned int i=0; i<UnitVec.size(); i++)
    {
        weight+=UnitVec[i].u_weight;
        xweight+=UnitVec[i].u_weight*UnitVec[i].u_LCG;
    }
    if (weight == 0)
    {
        return 0;
    }else {
    return xweight/weight;
    }
}

float Ship::unit_VCG()
{
    float weight=0, xweight=0;
    for (long unsigned int i=0; i<UnitVec.size(); i++)
    {
        weight+=UnitVec[i].u_weight;
        xweight+=UnitVec[i].u_weight*UnitVec[i].u_VCG;
    }
    if (weight == 0)
    {
        return 0;
    }else {
    return xweight/weight;
    }
}

float Ship::unit_TCG()
{
    float weight=0, xweight=0;
    for (long unsigned int i=0; i<UnitVec.size(); i++)
    {
        weight+=UnitVec[i].u_weight;
        xweight+=UnitVec[i].u_weight*UnitVec[i].u_TCG;
    }
    if (weight == 0)
    {
        return 0;
    }else {
    return xweight/weight;
    }
}

float Ship::deadLoad_weight()
{
    float weight=0;
    for (long unsigned int i=0; i<BulkVec.size(); i++)
    {
        weight+=BulkVec[i].u_weight;
    }
    return weight;
}

float Ship::deadLoad_lcg()
{
    float weight=0, xweight=0;
    for (long unsigned int i=0; i<BulkVec.size(); i++)
    {
        weight+=BulkVec[i].u_weight;
        xweight+=BulkVec[i].u_weight*BulkVec[i].u_LCG;
    }
    if (weight == 0)
    {
        return 0;
    }else {
    return xweight/weight;
    }
}

float Ship::deadLoad_vcg()
{
     float weight=0, xweight=0;
    for (long unsigned int i=0; i<BulkVec.size(); i++)
    {
        weight+=BulkVec[i].u_weight;
        xweight+=BulkVec[i].u_weight*BulkVec[i].u_VCG;
    }
    if (weight == 0)
    {
        return 0;
    }else {
    return xweight/weight;
    }
}

float Ship::deadLoad_tcg()
{
     float weight=0, xweight=0;
    for (long unsigned int i=0; i<BulkVec.size(); i++)
    {
        weight+=BulkVec[i].u_weight;
        xweight+=BulkVec[i].u_weight*BulkVec[i].u_TCG;
    }
    if (weight == 0)
    {
        return 0;
    }else {
    return xweight/weight;
    }
}

float Ship::deadweight()
{
    float weight=0;
    weight=deadLoad_weight()+unit_weight()+constants_weight();
    return weight;
}

float Ship::deadweight_lcg()
{
    if (deadLoad_weight()+unit_weight()+constants_weight() == 0)
        {
            return 0;

        }else{
            return (deadLoad_lcg()*deadLoad_weight()+unit_LCG()*unit_weight()+constants_LCG()*constants_weight())/(deadLoad_weight()+unit_weight()+constants_weight());
        }
}

float Ship::deadweight_vcg()
{
    if (deadLoad_weight()+unit_weight()+constants_weight() == 0)
        {
            return 0;

        }else{
            return (deadLoad_vcg()*deadLoad_weight()+unit_VCG()*unit_weight()+constants_VCG()*constants_weight())/(deadLoad_weight()+unit_weight()+constants_weight());
        }
}

float Ship::deadweight_tcg()
{
    if (deadLoad_weight()+unit_weight()+constants_weight() == 0)
        {
            return 0;

        }else{
            return (deadLoad_tcg()*deadLoad_weight()+unit_TCG()*unit_weight()+constants_TCG()*constants_weight())/(deadLoad_weight()+unit_weight()+constants_weight());
        }
}

float Ship::disp()
{
    return deadweight()+s_lightShip;
}

float Ship::disp_lcg()
{
    return (deadweight()*deadweight_lcg()+s_lightShip*s_LCGLight)/(deadweight()+s_lightShip);
}

float Ship::disp_vcg()
{
    return (deadweight()*deadweight_vcg()+s_lightShip*s_VCGLight)/(deadweight()+s_lightShip);
}

float Ship::disp_tcg()
{
    return (deadweight()*deadweight_tcg()+s_lightShip*s_TCGLight)/(deadweight()+s_lightShip);
}

float Ship::rest_dwt()
{
    return (s_maxDWT-deadweight());
}



// Upon calling a new unit in the UI, a new unit is added to the Units Vector.
void Ship::new_unit(u_types choice){
    Unit unit;
    unit.u_type = choice; // The choices from the top of this class
    UnitVec.push_back(unit);
}

// In case one unit is not wanted. This function takes an argument on, which unit is supposed to be deleted
void Ship::delete_unit(int row){
    UnitVec.erase(UnitVec.begin()+row);
}

/* Returns the count of units existing. This must be done through a function
since the Unit vector is not publicly available*/
int Ship::unit_count()
{
    int a = UnitVec.size();
    return a;
}

bool Ship::set_car_name(int row, std::string val)
{
    BulkVec[row].u_name=val;
    return true;
}
bool Ship::set_car_weight(int row, std::string val){
    return Ship::assign_val(val, BulkVec[row].u_weight);}

bool Ship::set_car_lcg(int row, std::string val){
    return Ship::assign_val(val, BulkVec[row].u_LCG);}

bool Ship::set_car_vcg(int row, std::string val){
    return Ship::assign_val(val, BulkVec[row].u_VCG);}

bool Ship::set_car_tcg(int row, std::string val){
    return Ship::assign_val(val, BulkVec[row].u_TCG);}

bool Ship::set_car_length(int row, std::string val){
    return Ship::assign_val(val, BulkVec[row].u_length);}

bool Ship::set_car_breadth(int row, std::string val){
    return Ship::assign_val(val, BulkVec[row].u_breadth);}

bool Ship::set_car_height(int row, std::string val){
    return Ship::assign_val(val, BulkVec[row].u_height);}

// Ship deconstructor
Ship::~Ship(){}

// Unit initial set
Ship::Unit::Unit(){
    u_LCG = 0.0f;
    u_TCG = 0.0f;
    u_VCG = 0.0f;
    u_length = 0.0f;
    u_breadth = 0.0f;
    u_height = 0.0f;
    u_volume = 0.0f;
    u_density = 0.0f;
    u_weight = 0.0f;
    u_fsm = 0.0f;
    u_maxfsm = false;
}
Ship::Unit::~Unit(){} // Unit deconstructor

Ship::Hydrostatistics::Hydrostatistics(){
    h_draft = 0.0f;
    h_weight = 0.0f;
    h_volume = 0.0f;
    h_tpc = 0.0f;
    h_kmt = 0.0f;
    h_lcb = 0.0f;
    h_lcf = 0.0f;
    h_mct = 0.0f;
}
Ship::Hydrostatistics::~Hydrostatistics(){}

Ship::crossCurves::crossCurves(){
    c_volume = 0.0f;
    c_ten = 0.0f;
    c_twenty = 0.0f;
    c_thirty = 0.0f;
    c_forty = 0.0f;
    c_sixty = 0.0f;
    c_eighty = 0.0f;
}
Ship::crossCurves::~crossCurves(){}

Ship::Stability::Stability()
{
    s_LCG = 0.0f;
    s_VCG = 0.0f;
    s_TCG = 0.0f;
    s_GZ = 0.0f;
}
Ship::Stability::~Stability(){}

Ship::Constants::Constants() {
    con_name = "";
    con_lcg = 0.0f;
    con_vcg = 0.0f;
    con_tcg = 0.0f;
    con_weight = 0.0f;
}
Ship::Constants::~Constants(){}
