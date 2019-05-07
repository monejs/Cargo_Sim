#include <string>
#include <vector>
#include <fstream>
#include <ios>
#include "Ship.pb.h"
//#include "Model.h"

#ifndef SHIP_H
#define SHIP_H

class Ship
{
public:
    Ship();

    static const std::string u_type_strings[8];
    enum u_types{Ballast, Cargo_Tank, Cargo_Hold, HFO, DO, LO, FW, Various};
    bool set_s_name(std::string);
    bool set_s_LOA(std::string);
    bool set_s_beam(std::string);
    bool set_s_height(std::string);
    bool set_s_strengthTank(std::string);
    bool set_s_strengthCover(std::string);
    bool set_s_minDraft(std::string);
    bool set_s_maxDraft(std::string);
    bool set_s_maxDWT(std::string);
    bool set_s_lightShip(std::string);
    bool set_s_LCGLight(std::string);
    bool set_s_TCGLight(std::string);
    bool set_s_VCGLight(std::string);
    std::string& read_s_name();
    float& read_s_LOA();
    float& read_s_beam();
    float& read_s_height();
    float& read_s_strengthTank();
    float& read_s_strengthCover();
    float& read_s_minDraft();
    float& read_s_maxDraft();
    int& read_s_maxDWT();
    int& read_s_lightShip();
    float& read_s_LCG();
    float& read_s_TCG();
    float& read_s_VCG();
    float& read_s_LCGLight();
    float& read_s_TCGLight();
    float& read_s_VCGLight();
    float& read_s_waterCondition();
    bool set_unit (int, int, std::string);
    std::string& read_unit_name (int);
    std::string read_unit_type (int);
    float& read_u_LCG(int x);
    float& read_u_VCG(int x);
    float& read_u_TCG(int x);
    float& read_u_weight(int x);
    float& read_u_volume(int x);
    float& read_u_dencity(int x);
    float read_u_maxvol (int);
    int unit_count();

    void new_unit(u_types);
    void delete_unit(int);
    void calculate();
    void save();
    bool load(std::string);

    virtual ~Ship();

private:
    bool assign_val(std::string&, float&);
    std::string s_name;
    float s_LOA;
    float s_beam;
    float s_height;
    float s_strengthTank;
    float s_strengthCover;
    float s_minDraft;
    float s_maxDraft;
    int s_maxDWT;
    int s_lightShip;
    float s_LCGLight;
    float s_TCGLight;
    float s_VCGLight;
    float s_waterCondition;

    class Unit
    {
    public:
        Unit();
        bool conflict (int, int);
        virtual ~Unit();

        std::string u_name;
        u_types u_type;
        float u_LCG;
        float u_TCG;
        float u_VCG;
        float u_length;
        float u_breadth;
        float u_height;
        float u_volume;
        float u_density;
        float u_weight;
        float u_fsm;
        float u_maxfsm;
    };
    class BulkCargo : public Unit
    {
    public:
        float pressure;
    };
    class Hydrostatistics
    {
    public:
        Hydrostatistics();
        virtual ~Hydrostatistics();

        float h_draft;
        float h_weight;
        float h_volume;
        float h_tpc;
        float h_mct;
        float h_kmt;
        float h_lcf;
        float h_lcb;
    };

    class crossCurves
    {
    public:
        crossCurves();
        virtual ~crossCurves();

        int c_volume;
        float c_ten;
        float c_twenty;
        float c_thirty;
        float c_forty;
        float c_sixty;
        float c_eighty;
    };
    class Stability
    {
    public:
        Stability();
        virtual ~Stability();
        float s_LCG;
        float s_TCG;
        float s_VCG;
        float s_GZ;
    };
    std::vector<Unit> UnitVec;
    std::vector<BulkCargo> BulkVec;
    std::vector<Hydrostatistics> HydroVec;
    std::vector<crossCurves> CrossVec;

    class Model
    {

    };
};
#endif // SHIP_H
