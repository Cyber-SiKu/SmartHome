#include "getstatuethread.h"
#include "yeelink_lzy.h"

extern "C" {
#include <stdio.h>
#include <unistd.h>
}

GetStatueThread::GetStatueThread() {}

void GetStatueThread::run() {
  while (1) {
    int ret = get_sensor_status("118.190.25.51", "359635", "410077",
                                "b36d241909a3db268eef175b26d40e23");
    if (ret < 0) {
      fprintf(stderr, "%s\n", "get bedroom led's states error!");
    } else if (ret) {
      fprintf(stdout, "%s\n", "bedroom led : on");
      emit statueSignal(BEDROOMLED, LED_ON);
    } else {
      fprintf(stdout, "%s\n", "bedroom led : off");
      emit statueSignal(BEDROOMLED, LED_OFF);
    }

    fflush(stdout);
    sleep(1);
    ret = get_sensor_status("118.190.25.51", "359635", "409844",
                            "b36d241909a3db268eef175b26d40e23");
    if (ret < 0) {
      fprintf(stderr, "%s\n", "get parlour led's states error!");
    } else if (ret) {
      fprintf(stdout, "%s\n", "parlour led : on");
      emit statueSignal(PARLOURLED, LED_ON);
    } else {
      fprintf(stdout, "%s\n", "parlour led : off");
      emit statueSignal(PARLOURLED, LED_OFF);
    }

    fflush(stdout);
    sleep(1);
    ret = get_sensor_status("118.190.25.51", "359635", "409881",
                            "b36d241909a3db268eef175b26d40e23");
    if (ret < 0) {
      fprintf(stderr, "%s\n", "get kitchen led's states error!");
    } else if (ret) {
      fprintf(stdout, "%s\n", "kitchen led : on");
      emit statueSignal(KITCHENLED, LED_ON);
    } else {
      fprintf(stdout, "%s\n", "kitchen led : off");
      emit statueSignal(KITCHENLED, LED_OFF);
    }

    fflush(stdout);
    sleep(1);
    ret = get_sensor_status("118.190.25.51", "359635", "410078",
                            "b36d241909a3db268eef175b26d40e23");
    if (ret < 0) {
      fprintf(stderr, "%s\n", "get buzzer's states error!");
    } else if (ret) {
      fprintf(stdout, "%s\n", "buzzer : on");
      emit statueSignal(BUZZER, BUZZER_ON);
    } else {
      fprintf(stdout, "%s\n", "buzzer: off");
      emit statueSignal(BUZZER, BUZZER_OFF);
    }

    fflush(stdout);
    sleep(1);
    emit statueSignal(5, 6);
  }
}
