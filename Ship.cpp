#include "Ship.h"

//Declares the possible types of units a user can make
const std::string Ship::u_type_strings[8] = {"Ballast", "Cargo Tank", "Cargo Hold", "HFO", "DO", "LO", "FW", "Various"};

// Function to check, if the input from user is valid and returns false, if not
bool Ship::assign_val(std::string& in_t, float& var)
{
    if (::atof(in_t.c_str()))
    {
        var = ::atof(in_t.c_str());
        return true;
    }else{ return false; }
}

// Still working on this one
void Ship::calculate()
{
    StandartShip standartship;
    standartship.sectionlength = s_LOA/10;
    standartship.section_beam = {0.23f*s_beam, 0.6f*s_beam, s_beam, s_beam, s_beam, s_beam, s_beam, 0.75f*s_beam, 0.5f*s_beam, 0.25f*s_beam};
    standartship.section_draft = {0.9f*s_maxDraft, s_maxDraft, s_maxDraft, s_maxDraft, s_maxDraft, s_maxDraft, s_maxDraft, 0.8f*s_maxDraft, 0.5f*s_maxDraft, 0.3f*s_maxDraft};

    for (float i=s_minDraft; i<s_maxDraft; i+=0.1f)
    {

    }
}

// Calculates the ships particulars automagicly, if so wished. This function is available over the particulars input mask.
void Ship::autoParticulars()
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

// Saves all the data to file using the google protobuf protocol.
// Quite easy to use and can be generates automatically.
void Ship::save()
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
        unit->set_volume(UnitVec[i].u_volume);
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
    for (long unsigned int i=0; i<HydroVec.size(); i++)
    {
        ship::Hydrostat* hydrostat = SaveShip.add_hydrostat();
        hydrostat->set_draft(HydroVec[i].h_draft);
        hydrostat->set_volume(HydroVec[i].h_volume);
        hydrostat->set_weight(HydroVec[i].h_weight);
        hydrostat->set_tpc(HydroVec[i].h_tpc);
        hydrostat->set_kmt(HydroVec[i].h_kmt);
        hydrostat->set_lcb(HydroVec[i].h_lcb);
        hydrostat->set_lcf(HydroVec[i].h_lcf);
        hydrostat->set_mct(HydroVec[i].h_mct);
    }
    for (long unsigned int i=0; i<CrossVec.size(); i++)
    {
        ship::crossCurves* curves = SaveShip.add_crosscurves();
        curves->set_volume(CrossVec[i].c_volume);
        curves->set_ten(CrossVec[i].c_ten);
        curves->set_twenty(CrossVec[i].c_twenty);
        curves->set_thirty(CrossVec[i].c_thirty);
        curves->set_forty(CrossVec[i].c_forty);
        curves->set_sixty(CrossVec[i].c_sixty);
        curves->set_eighty(CrossVec[i].c_eighty);
    }
    std::string filename = s_name+".ship"; // Program specific filename
    std::fstream output(filename,  std::ios::out | std::ios::trunc | std::ios::binary); // Creating file
    SaveShip.SerializeToOstream(&output); // Writing to file
    output.close(); // File closed
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
            UnitVec[i].u_volume = unit1.volume();
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
                    UnitVec[i].u_type = u_types::FW;
                    break;
            }
        }
        for (int i=0; i<BodyOfShip.bulk_size(); i++)
        {
            BulkCargo bulk;
            BulkVec.push_back(bulk);
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
        for (int i=0; i<BodyOfShip.hydrostat_size(); i++)
        {
            Hydrostatistics hydro;
            HydroVec.push_back(hydro);
            const ship::Hydrostat& st = BodyOfShip.hydrostat(i);
            HydroVec[i].h_draft = st.draft();
            HydroVec[i].h_volume = st.volume();
            HydroVec[i].h_weight = st.weight();
            HydroVec[i].h_kmt = st.kmt();
            HydroVec[i].h_lcb = st.lcb();
            HydroVec[i].h_lcf = st.lcf();
            HydroVec[i].h_mct = st.mct();
            HydroVec[i].h_tpc = st.tpc();
        }
        return true; // At the end returns true
    }
}


Ship::Ship() // Declaration of the Ships null state.
{
    s_name = "Ship1"; // Simple name with intention, it will be changed
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
bool Ship::set_s_minDraft(std::string in_t){
    return Ship::assign_val(in_t, s_minDraft);
}
bool Ship::set_s_maxDraft(std::string in_t){
    return Ship::assign_val(in_t, s_maxDraft);
}
bool Ship::set_s_maxDWT(std::string in_t){
    if (atoi(in_t.c_str()))
    {
        s_maxDWT = atoi(in_t.c_str());
        return true;
    }else{return false;}
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

// These functions return references to the actual values, so nothing is copied over
std::string& Ship::read_s_name(){return s_name;}

float& Ship::read_s_LOA(){return s_LOA;}

float& Ship::read_s_beam(){return s_beam;}

float& Ship::read_s_height(){return s_height;}

float& Ship::read_s_strengthTank(){return s_strengthTank;}

float& Ship::read_s_strengthCover(){return s_strengthCover;}

float& Ship::read_s_minDraft(){return s_minDraft;}

float& Ship::read_s_maxDraft(){return s_maxDraft;}

int& Ship::read_s_maxDWT(){return s_maxDWT;}

int& Ship::read_s_lightShip(){return s_lightShip;}

float& Ship::read_s_LCGLight(){return s_LCGLight;}

float& Ship::read_s_TCGLight(){return s_TCGLight;}

float& Ship::read_s_VCGLight(){return s_VCGLight;}

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
    return UnitVec[x].u_VCG;}
float& Ship::read_u_volume(int x){
    return UnitVec[x].u_volume;}

float& Ship::read_u_dencity(int x){
    return UnitVec[x].u_density;}

// The maximum volume is never saved, but always recalculated for more accuracy
float Ship::read_u_maxvol(int i){
return (UnitVec[i].u_length * UnitVec[i].u_breadth * UnitVec[i].u_height);}

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

// Row is the unit number, col is the unit particular to be changed and val is the value, it is supposed to be set to
bool Ship::set_unit(int row, int col, std::string val)
{
    switch (col) // A simple switch case is good enough
    {
    case (0):
        UnitVec[row].u_name = val;
        return true;
    case (1):
        if (val == u_type_strings[0]) UnitVec[row].u_type = u_types::Ballast;
        if (val == u_type_strings[1]) UnitVec[row].u_type = u_types::Cargo_Tank;
        if (val == u_type_strings[2]) UnitVec[row].u_type = u_types::Cargo_Hold;
        if (val == u_type_strings[3]) UnitVec[row].u_type = u_types::HFO;
        if (val == u_type_strings[4]) UnitVec[row].u_type = u_types::DO;
        if (val == u_type_strings[5]) UnitVec[row].u_type = u_types::LO;
        if (val == u_type_strings[6]) UnitVec[row].u_type = u_types::FW;
        if (val == u_type_strings[7]) UnitVec[row].u_type = u_types::Various;
        return true;
    case (2):
        return (Ship::assign_val(val, UnitVec[row].u_LCG));
    case (3):
        return (Ship::assign_val(val, UnitVec[row].u_TCG));
    case (4):
        return (Ship::assign_val(val, UnitVec[row].u_VCG));
    case (5):
        return (Ship::assign_val(val, UnitVec[row].u_length));
    case (6):
        return (Ship::assign_val(val, UnitVec[row].u_breadth));
    case (7):
        return (Ship::assign_val(val, UnitVec[row].u_height));
    default:
        return false;
    }
}
/* Returns the count of units existing. This must be done through a function
since the Unit vector is not publicly available*/
int Ship::unit_count()
{
    int a = UnitVec.size();
    return a;
}

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
