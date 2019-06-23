#ifndef SHIP_H
#define SHIP_H

#include <string>
#include <vector>
#include <fstream>
#include <ios>
#include <iostream>
#include <sstream>
#include <math.h>
#include <cmath>
#include <iomanip>
#include <stdio.h>
#include <time.h>


#include "Ship.pb.h"

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
    bool set_s_minDraft();
    bool set_s_maxDraft(std::string);
    bool set_s_maxDWT();
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
    float read_s_maxDWT();
    int& read_s_lightShip();
    float& read_s_LCG();
    float& read_s_TCG();
    float& read_s_VCG();
    float& read_s_LCGLight();
    float& read_s_TCGLight();
    float& read_s_VCGLight();
    float& read_s_waterCondition();
    float read_s_volume();
    float last_kn(int, float);

    bool set_u_name(int, std::string);
    bool set_u_type(int, std::string);
    bool set_u_lcg(int, std::string);
    bool set_u_vcg(int, std::string);
    bool set_u_tcg(int, std::string);
    bool set_u_height (int, std::string);
    bool set_u_length (int, std::string);
    bool set_u_breadth (int, std::string);
    bool set_u_weight (int, std::string);
    bool set_u_vol (int, std::string);
    bool set_u_pvol (int, std::string);
    bool set_u_density(int, std::string);

    std::string& read_unit_name (int);
    std::string read_unit_type (int);
    float& read_u_LCG(int x);
    float& read_u_VCG(int x);
    float& read_u_TCG(int x);
    float& read_u_weight(int x);
    float read_u_volume(int x);
    float& read_u_density(int x);
    float& read_u_length(int x);
    float& read_u_breadth(int);
    float& read_u_height(int);
    float read_u_maxvol (int);
    float read_u_fsmax(int);
    float read_u_pvol(int);

    bool set_con_name(int, std::string);
    bool set_con_lcg(int, std::string);
    bool set_con_tcg(int, std::string);
    bool set_con_vcg(int, std::string);
    bool set_con_weight(int, std::string);
    bool set_con_start(int, std::string);
    bool set_con_end(int, std::string);

    float gm();

    float constants_weight();
    float constants_LCG();
    float constants_VCG();
    float constants_TCG();

    float unit_weight();
    float unit_LCG();
    float unit_VCG();
    float unit_TCG();

    float deadLoad_weight();
    float deadLoad_lcg();
    float deadLoad_vcg();
    float deadLoad_tcg();

    float deadweight();
    float deadweight_lcg();
    float deadweight_vcg();
    float deadweight_tcg();

    float disp();
    float disp_lcg();
    float disp_vcg();
    float disp_tcg();

    float rest_dwt();

    bool set_car_name(int, std::string);
    bool set_car_weight(int, std::string);
    bool set_car_lcg(int, std::string);
    bool set_car_vcg(int, std::string);
    bool set_car_tcg(int, std::string);
    bool set_car_length(int, std::string);
    bool set_car_breadth(int, std::string);
    bool set_car_height(int, std::string);

    float init_heel();
    float trim();

    void variable_update();
    void shipSize();
    int unit_count();
    void autoParticulars();
    void text_print();
    void clear_data();
    const std::string currentDateTime();
    float stabi(int);
    float find_draft(float);
    void gz_curve();

    void new_unit(u_types);
    void delete_unit(int);
    void calculate();
    bool save(std::string);
    bool load(std::string);
//    void modelLoad();

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
    float s_VCG, s_bm;
    float s_waterCondition;
    float s_volume;
    float s_gm;
    float s_km;
    float hull_LCG;
    float sectionlength;
    std::array<float, 10> section_area;
    std::array<float, 10> section_vol;
    std::array<float, 10> section_G;
    std::array<float, 10> section_LCG;
    std::array<float, 10> section_BM;
    std::array<float, 10> section_BMl;
    std::array<float, 10> section_KM;
    std::array<float, 10> section_B;
    std::array<float, 10> section_beam;
    std::array<float, 10> section_height;
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
        float u_xmin, u_xmax;
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

    class Constants
    {
    public:
        Constants();
        virtual ~Constants();
        std::string con_name;
        float con_lcg;
        float con_tcg;
        float con_vcg;
        float con_weight;
        float con_start;
        float con_end;

    };
//    std::vector<std::vector<float>> points;
    std::vector<Unit> UnitVec;
    std::array<BulkCargo, 50> BulkVec;
    std::vector<Hydrostatistics> HydroVec;
    std::vector<crossCurves> CrossVec;
    std::array<Constants, 50> ConVec;

//    struct rib
//    {
//        float x;
//        std::vector<std::vector<float>> zy;
//    };
//    std::vector<rib> ribs;
}; // End Ship class
#endif // SHIP_H
