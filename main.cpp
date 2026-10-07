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


int main(){
    int max_attempt = 3;
    if(!userSecurity(max_attempt)){
        return 0;
    }

    std::cout << "\nwelcome to the program\n\n";

    std::srand(std::time(0));
    int humidity = std::rand() % 101;

    std::cout << "nilai kelembapan saat ini: "<< humidity;
    std::string humidity_status;

    if(humidity >= 0 && humidity <= 30){
        humidity_status = "kering";
        std::cout <<"\nstatus kelembapan: " << humidity_status;
    }
    else if (humidity >= 31 && humidity <= 70)
    {
        humidity_status = "lembab";
        std::cout <<"\nstatus kelembapan: " << humidity_status;
    }
    else
    {
        humidity_status = "basah";
        std::cout <<"\nstatus kelembapan: " << humidity_status;
    }

    bool user_water = 0;

    std::cout << "\ningin menyiram tanaman? (1/0): ";

    do{
        std::cin >> user_water;
        if (user_water){
            humidity += 20;
            std::cout << "\npenyiraman dilakukan!" << humidity;
            std::cout << "\nhumidity saat ini: " << humidity << "\nstatus: " << humidity_status;
        }
        else{
            continue;
        }
        std::cout << "\ningin menyiram lagi? (1/0): ";
    } while (user_water == true);

    bool user_ac = 0;
    int user_control_temp;
    double temp_ac_celcius;
    bool ac_condition = false;

    std::cout << "\ningin kontrol AC? (1/0): ";

    do{
        std::cin >> user_ac;

        if (user_ac){
            std::cout << "\natur suhu AC:\n(0) off\n(1) low\n(2) medium\n(3) high\n";
            std::cin >> user_control_temp;

            switch (user_control_temp)
            {
            case 0:
                ac_condition = false;
                break;
            case 1:
                ac_condition = true;
                temp_ac_celcius = 30;
                break;
            case 2:
                ac_condition = true;
                temp_ac_celcius = 22;
                break;
            case 3:
                ac_condition = true;
                temp_ac_celcius = 14;
                break;
            default:
                std::cout << "invalid input";
                break;
            }
        }
        else{
            continue;
        }
        if(ac_condition){
            std::cout << "suhu ac: " << temp_ac_celcius;
        }
        else{
            std::cout << "ac tetap mati";
        }

        std::cout << "\ningin kontrol lagi? (1/0): ";
    } while (user_ac == true);

    int lamp_light;
    bool lamp_status;
    bool user_light;
    int user_input_lamp;

    std::cout << "\ningin kontrol lampu? (1/0): ";

        do{
            std::cin >> user_light;

        if(user_light){
            std::cout << "atur pencahayaan lampu (0-100)";
            std::cin >> user_input_lamp;

            if (user_input_lamp != 0)
            {
                lamp_light = user_input_lamp;
                lamp_status = true;
            }
            else
            {
                lamp_status = false;
            }
        }
        else{
            continue;
        }

        if(lamp_status){
            std::cout << "lampu dinyalakan!\nlamp value = " << lamp_light;
        }
        else{
            std::cout << "lampu masih mati";
        }

        std::cout << "ingin kontrol lagi? (1/0)";
    } while (user_light == true);

    std::cout << "\nu are out";
}


int powerLamp(int lamp_light){
    double power_lamp = (lamp_light / 100) * 15;
    return power_lamp;
}

int powerAc(int temp_ac_celcius){
    double power_ac = (temp_ac_celcius / 100) * 35;
    return power_ac;
}

