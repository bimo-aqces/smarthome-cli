#include <iostream>
#include <cmath>
#include <ctime>

const int pass_system = 1234;

bool userSecurity(int max_attempt){
    int pass_input;
    int user_attempt = 0;
    do
    {
        user_attempt += 1;

        std::cout << "\ninput pass: ";
        std::cin >> pass_input;

        if (pass_input != pass_system)
        {
            std::cout << "\nwrong password, attemp: " << user_attempt;
            if (user_attempt >= max_attempt)
            {
                std::cout << "\nu reached max attemp\n";
                return false;
            }
        }
        else
        {
            return true;
        }
    } while (pass_input != pass_system);

    return false;
}

int showHumidityValue(){
    int humidity = std::rand() % 101;
    return humidity;
}


std::string showHumidityStatus(int humidity_value){
    std::string humidity_status;

    if (humidity_value >= 0 && humidity_value <= 30)
    {
        humidity_status = "kering";
        return humidity_status;
    }
    else if (humidity_value >= 31 && humidity_value <= 70)
    {
        humidity_status = "lembab";
        return humidity_status;
    }
    else
    {
        humidity_status = "basah";
        return humidity_status;
    }
}


void waterMenu(int &humidity_value){
    bool user_water = 0;

    std::cout << "\ningin menyiram tanaman? (1/0): ";

    do
    {
        std::cin >> user_water;
        if (user_water)
        {
            humidity_value += 20;
            std::cout << "\npenyiraman dilakukan!\n";
        }
        else
        {
            continue;
        }
        std::cout << "\ningin menyiram lagi? (1/0): ";
    } while (user_water == true);
}

int acValue(){
    int user_control_temp;
    int temp_ac_celcius;
    std::cout << "\natur suhu AC:\n(0) off\n(1) low\n(2) medium\n(3) high\n";
    std::cin >> user_control_temp;

    switch (user_control_temp)
    {
    case 0:
        return 0;
    case 1:
        temp_ac_celcius = 30;
        return temp_ac_celcius;
        break;
    case 2:
        temp_ac_celcius = 22;
        return temp_ac_celcius;
        break;
    case 3:
        temp_ac_celcius = 14;
        return temp_ac_celcius;
        break;
    default:
        std::cout << "invalid input";
        return 0;
    }
    }

bool acStatus(int &temp_ac_celcius){
    if(temp_ac_celcius){
        return true;
    }
    else{
        return false;
    }
}

void acMenu(int &ac_value, bool &ac_status){
    bool user_ac;
    std::cout << "\ningin kontrol AC? (1/0): ";

    do
    {
        std::cin >> user_ac;

        if (user_ac)
        {
            ac_value = acValue();
            ac_status = acStatus(ac_value);
            std::cout << "ac value = " << ac_value << "\nac status = " << ac_status;
        }
        else
        {
            continue;
        }

        std::cout << "\ningin kontrol lagi? (1/0): ";
    } while (user_ac == true);
}

int lampValue(){

    int lamp_light;
    std::cout << "atur pencahayaan lampu (0-100): ";
    std::cin >> lamp_light;
    return lamp_light;

}

bool lampStatus(int lamp_light){
    if(lamp_light != 0){
        return true;
    }
    else{
        return false;
    }

}

void lampMenu(int &lamp_light, bool &lamp_status){

    bool user_light;

    std::cout << "\ningin kontrol lampu? (1/0): ";

    do
    {
        std::cin >> user_light;

        if (user_light)
        {
            lamp_light = lampValue();
            lamp_status = lampStatus(lamp_light);
            std::cout << "lamp value: " <<lamp_light << "\nlamp status: " <<  lamp_status << '\n';
            
        }
        else
        {
            continue;
            
        }

        std::cout << "ingin kontrol lagi? (1/0) ";
    } while (user_light == true);
}

double getPowerLamp(double lamp_value){
    double power_lamp_value = lamp_value * 15 / 100;
    return power_lamp_value;
}

double getPowerAC(int ac_value)
{   
    if(ac_value == 0){
        return 0;
    }
    else{
        double power_ac_value = 750 + (24 - ac_value) * 35;
        return power_ac_value;
    }
}

void powerMenu(double power_ac, double power_light){
    double power_value = power_ac + power_light;
    std::cout << "\nAC Power = " << power_ac << '\n' << "Lamp Power = " << power_light <<'\n';
    std::cout << "Total Power = " << power_value << '\n';
}


int main()
{
    int max_attempt = 3;
    if(!userSecurity(max_attempt)){
        return 0;
    }
    std::srand(std::time(0));

    int menu_input;
    bool user_retry = false;

    int humidity_value = showHumidityValue();
    std::string humidity_status = showHumidityStatus(humidity_value);

    int lamp_light = 0;
    bool lamp_status = false;

    int ac_value = 0;
    bool ac_status = false;


    do{
        std::cout << "\nwelcome to the program\n(1) Watering\n(2) Control AC\n(3) Control Lamp\n(4) Power info\n";
        std::cin >> menu_input;
        switch (menu_input)
        {
        case 1:
        {
            std::cout << "Humidity Info:\nValue = " << humidity_value << '%' << "\nStatus = " << humidity_status;
            waterMenu(humidity_value);
            humidity_status = showHumidityStatus(humidity_value);
            std::cout << "Humidity Info:\nValue = " << humidity_value << '%' << "\nStatus = " << humidity_status;
            std::cout << "\nback to main menu? (0/1)";
            std::cin >> user_retry;
            break;
        }
        case 2:
        {
            acMenu(ac_value, ac_status);
            std::cout << "back to main menu? (0/1)";
            std::cin >> user_retry;
            break;
        }
        case 3:
        {
            lampMenu(lamp_light, lamp_status);
            std::cout << "back to main menu? (0/1)";
            std::cin >> user_retry;
            break;
        }
        case 4:{
            double power_ac = getPowerAC(ac_value);
            double power_lamp = getPowerLamp(lamp_light);
            powerMenu(power_ac, power_lamp);
            std::cout << "back to main menu? (0/1)";
            std::cin >> user_retry;
            break;
        }

        default:
            std::cout << "invalid";
            break;
        }
    } while (user_retry == true);

    std::cout << "Adjustment Recap:\n";
    std::cout << "(1) Humidity Value: " << humidity_value << '(' << humidity_status << ")\n";
    std::cout << "(2) Lamp light :" << lamp_light << '(' << lamp_status << ")\n";
    std::cout << "(3) AC Value :" << ac_value << '(' << ac_status << ")\n";
    std::cout << "(4) Power Net :" << getPowerAC(ac_value) + getPowerLamp(lamp_light) << '\n' << "AC Power: " << getPowerAC(ac_value) << '\n' << "Lamp Power: " << getPowerLamp(lamp_light) << '\n';
}

