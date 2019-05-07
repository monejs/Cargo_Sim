#include "Ship.h"

const std::string Ship::u_type_strings[8] = {"Ballast", "Cargo Tank", "Cargo Hold", "HFO", "DO", "LO", "FW", "Various"};


bool Ship::assign_val(std::string& in_t, float& var)
{
    if (::atof(in_t.c_str()))
    {
        var = ::atof(in_t.c_str());
        return true;
    }else{ return false; }
}

void Ship::calculate()
{
     std::string text = "Bulki.txt";
   // model.read_data(text);
}
void Ship::save()
{
    ship::ShipBodyData SaveShip;
    ship::ShipData* shipdata = SaveShip.add_shipdata();
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
    std::string filename = s_name+".ship";
    std::fstream output(filename,  std::ios::out | std::ios::trunc | std::ios::binary);
    SaveShip.SerializeToOstream(&output);
    output.close();
}
bool Ship::load(std::string file)
{
    std::fstream input(file, std::ios::in | std::ios::binary);
    ship::ShipBodyData BodyOfShip;
    if (!BodyOfShip.ParseFromIstream(&input))
    {
        return false;
    }else{
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
        return true;
    }
}


Ship::Ship()
{
    s_name = "Ship1";
    s_LOA = 0.0f;
    s_beam = 0.0f;
    s_height = 0.0f;
    s_lightShip = 0;
    s_strengthTank = 20.0f;
    s_strengthCover = 5.0f;
    s_minDraft = 0.0f;
    s_maxDraft = 0.0f;
    s_maxDWT = 0;
    s_waterCondition = 1.025;
}
bool Ship::set_s_name(std::string in_t){
    if (in_t != "")
    {
        s_name = in_t;
        return true;
    }else{return false;}
}
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

float Ship::read_u_maxvol(int i){
return (UnitVec[i].u_length * UnitVec[i].u_breadth * UnitVec[i].u_height);}

void Ship::new_unit(u_types choice){
    Unit unit;
    unit.u_type = choice;
    UnitVec.push_back(unit);
}

void Ship::delete_unit(int row){
    UnitVec.erase(UnitVec.begin()+row);
}
bool Ship::set_unit(int row, int col, std::string val)
{
    switch (col)
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

int Ship::unit_count()
{
    int a = UnitVec.size();
    return a;
}

Ship::~Ship(){}

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
Ship::Unit::~Unit(){}

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
