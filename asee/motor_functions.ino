void move_motor(int motor_number, int spd) {
  if(motor_number == 1) {
    analogWrite(en1,spd);
    digitalWrite(dir1,HIGH);
  } 
  else if (motor_number == 2) {
    analogWrite(en2,spd);
    digitalWrite(dir2,HIGH);
  } 
  else if (motor_number == 3) {
    analogWrite(en3,spd);
    digitalWrite(dir3,HIGH);
  } 
  else if (motor_number == 4) {
    analogWrite(en4,spd);
    digitalWrite(dir4, HIGH);
  }
  
}

void all_stop() {
analogWrite(en1,0);
analogWrite(en2,0);
analogWrite(en3,0);
analogWrite(en4,0);
}


void all_forward(int spd) {
  for(int i = 1; i<=4; i++) {
    move_motor(i,spd);
  }
}

void drift_left(int max_speed, int lower_speed) {
  move_motor(2,max_speed);
  move_motor(1,lower_speed);
 move_motor(3,lower_speed);
  move_motor(4,max_speed);
}

void drift_right(int max_speed, int lower_speed) {
  move_motor(1,max_speed);
 move_motor(2,lower_speed);
 move_motor(4,lower_speed);
  move_motor(3,max_speed);
}
