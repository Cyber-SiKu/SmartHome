#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "yeelink_lzy.h"

int main(int argc, char const *argv[]) {
  double temp = 25.9;
  int humi = 30;
  int switch_key = 0;

  /*
  * 1. 把温度和湿度传送到yeelink
  × 2. 从yeelink获取开关状态
  */

  while (1) {
    temp+=0.2;
    if (temp > 35) {
      temp = 29.5;
    }
    humi +=2;
    if (humi > 50) {
      humi = 30;
    }
    set_sensor_data("118.190.25.51", "359635","409773", "b36d241909a3db268eef175b26d40e23",temp);
    set_sensor_data("118.190.25.51", "359635","409807", "b36d241909a3db268eef175b26d40e23" ,humi);
    switch_key =  get_sensor_status("118.190.25.51", "359635", "409844","b36d241909a3db268eef175b26d40e23");
    char * pwd;
    int reboot = get_sensor_status("118.190.25.51", "359635", "409881","b36d241909a3db268eef175b26d40e23");
    if(reboot == 1){
      printf("%s\n", "reboot");
      system("reboot");
    }
    switch(switch_key){
      case 0:
      printf("%s\n", "off");
      break;
      case 1:
      printf("%s\n", "on");
     break;
      default:
      printf("[%d] [%s : get_sensor_status] %s %d\n",__LINE__,__FUNCTION__, "undefined status: ", switch_key);
      break;
    }
    sleep(15);
  }

  return 0;
}
