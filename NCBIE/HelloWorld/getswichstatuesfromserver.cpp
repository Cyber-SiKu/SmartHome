#include "getswichstatuesfromserver.h"
#include "yeelink_lzy.h"

GetSwichStatuesFromServer::GetSwichStatuesFromServer()
{

}

void GetSwichStatuesFromServer::run()
{
    //emit switchSignal once every;
    bool flag = true;
    while (1) {
        int ret  = get_sensor_status("118.190.25.51", "359635", "409844","b36d241909a3db268eef175b26d40e23");
        if (ret == 0) {
            flag = false;
        }else if (ret == 1){
            flag = true;
        }else {
            //error
        }
        emit switchSignal(flag);
//        flag = !flag;
        sleep(2);
    }
}
