#include "jsonFile.h"

#include <fstream>

int main() {

    std::ofstream outFile;
    
#ifdef NO_BOOST
    outFile.open("jsonOutputNoBoost.json");
#else
    outFile.open("jsonOutputBoost.json");
#endif

    jsonFile f;

    /* TODO:
    jsonObj = f["nomeObj"];

    jsonObj obj("nomeObj");
    f["nomeObj"] = obj;

    al posto di add e get
    */
    jsonObj obj1 = f.getObj("jsonObj_elegante1");
    obj1["keyElegante_1_1"] = "valoreElegante1";
    obj1["keyElegante_1_2"] = 1;
    obj1["keyElegante_1_3"] = 1.1;

    jsonObj obj2 = f.getObj("jsonObj_elegante2");
    obj2["keyElegante_2_1"] = "valoreElegante2";
    obj2["keyElegante_2_2"] = 1;
    obj2["keyElegante_2_3"] = 1.1;
    
    // std::cout << f;

    /* Gestione dell'oggetto da solo */
    jsonObj obj3("jsonObj_alone");
    obj3["keyAlone_3_1"] = "valoreAlone";
    obj3["keyAlone_3_2"] = 1;
    obj3["keyAlone_3_3"] = 1.1;

    /* Posso stamparlo singolarmente */
    // std::cout << obj3;    

    /* Posso aggiungerlo al file */
    f.addObj(obj3);

    // std::cout << f;
    outFile << f;

    // jsonObject obj3("jsonObj_alone");
    // obj3["keyAlone_3_1"] = "valoreAlone";
    // obj3["keyAlone_3_2"] = 1;
    // obj3["keyAlone_3_3"] = 1.1;

    // std::cout << obj3;

    outFile.close();

    return 0;
}