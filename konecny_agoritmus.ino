#include <Servo.h>

Servo s_rotace;
Servo s_preklop;

int rychlost = 5;
int rameno_poz = 1;
int delay_time = 200;
int rotace_poz = 90;
int preklop_poz = 95;
int progres = 1;
boolean rohy = false;

char b_strana[9] = {'b', 'b', 'b',
                    'b', 'b', 'b',
                    'b', 'b', 'b',
                   };
char m_strana[9] = {'m', 'm', 'm',
                    'm', 'm', 'm',
                    'm', 'm', 'm',
                   };
char c_strana[9] = {'c', 'c', 'c',
                    'c', 'c', 'c',
                    'c', 'c', 'c',
                   };
char z_strana[9] = {'z', 'z', 'z',
                    'z', 'z', 'z',
                    'z', 'z', 'z',
                   };
char o_strana[9] = {'o', 'o', 'o',
                    'o', 'o', 'o',
                    'o', 'o', 'o',
                   };
char y_strana[9] = {'y', 'y', 'y',
                    'y', 'y', 'y',
                    'y', 'y', 'y',
                   };

int pohni_servo(int start, int konec, int pin) {   //motůrek na daném pinu se pohne o daný počet kroků(stupňů)

  int poz;

  if (start - konec < 0) {

    for (poz = start; poz <= konec; poz += 1) {

      if (pin == 9) {

        s_rotace.write(poz);
        delay(rychlost);
      }
      else if (pin == 10) {

        s_preklop.write(poz);
        delay(rychlost);
      }

    }


  }
  else {

    for (poz = start; poz >= konec; poz -= 1) {

      if (pin == 9) {
        s_rotace.write(poz);
        delay(rychlost);

      }
      else if (pin == 10) {
        s_preklop.write(poz);
        delay(rychlost);

      }

    }



  }

  if (pin == 9) {
    rotace_poz = poz;

  }

  if (pin == 10) {

    preklop_poz = poz;
  }
  delay(delay_time);

}

void podrz () {  //pohne rameno do pozice podrž

  pohni_servo(preklop_poz, 70, 10);
  rameno_poz = 2;   //kostka je držena
  delay(delay_time);
}
void pust () {   //pohne rameno do výchozí pozice

  pohni_servo(preklop_poz, 95, 10);
  rameno_poz = 1;   //kostka není držena
  delay(delay_time);
}

void preklop () {  //rameno překlopí kostku

  pohni_servo(preklop_poz, 20, 10);
  delay(400);
  pust();
  delay(200);
}

void otoc_poz1() { //pohne otočnou desku do pozice 1, která se rovná stupni 0


  pohni_servo(rotace_poz, 0, 9);
  delay(delay_time);



}

void otoc_poz2() {   //pohne otočnou desku do pozice 2, která se rovná stupni 90



  pohni_servo(rotace_poz, 90, 9);
  delay(delay_time);


}

void otoc_poz3() {    //pohne otočnou desku do pozice 3, která se rovná stupni 180


  pohni_servo(rotace_poz, 180, 9);
  delay(delay_time);




}


void prava() {  //otočí levou stranou nahoru, přepíše stav kostky

  

  char p_zl[9];
  char p_m[9];
  char p_b[9];
  char p_z[9];
  char p_c[9];

  for (int i = 0; i < 9; i++) {
    p_zl[i] = y_strana[i];
    p_m[i] = m_strana[i];
    p_b[i] = b_strana[i];
    p_z[i] = z_strana[i];
    p_c[i] = c_strana[i];

  }


  y_strana[0] = p_m[8];
  y_strana[3] = p_m[5];
  y_strana[6] = p_m[2];

  z_strana[0] = p_zl[0];
  z_strana[3] = p_zl[3];
  z_strana[6] = p_zl[6];

  b_strana[6] = p_z[0];
  b_strana[7] = p_z[3];
  b_strana[8] = p_z[6];

  m_strana[8] = p_b[6];
  m_strana[5] = p_b[7];
  m_strana[2] = p_b[8];

  c_strana[0] = p_c[2];
  c_strana[1] = p_c[5];
  c_strana[2] = p_c[8];
  c_strana[3] = p_c[1];
  c_strana[4] = p_c[4];
  c_strana[5] = p_c[7];
  c_strana[6] = p_c[0];
  c_strana[7] = p_c[3];
  c_strana[8] = p_c[6];






}

void prava_z() {     //otočí levou stranou dole, přepíše stav kostky


  char p_zl[9];
  char p_m[9];
  char p_b[9];
  char p_z[9];
  char p_c[9];

  for (int i = 0; i < 9; i++) {
    p_zl[i] = y_strana[i];
    p_m[i] = m_strana[i];
    p_b[i] = b_strana[i];
    p_z[i] = z_strana[i];
    p_c[i] = c_strana[i];

  }


  y_strana[0] = p_z[0];
  y_strana[3] = p_z[3];
  y_strana[6] = p_z[6];

  z_strana[0] = p_b[6];
  z_strana[3] = p_b[7];
  z_strana[6] = p_b[8];

  b_strana[6] = p_m[8];
  b_strana[7] = p_m[5];
  b_strana[8] = p_m[2];

  m_strana[8] = p_zl[0];
  m_strana[5] = p_zl[3];
  m_strana[2] = p_zl[6];

  c_strana[0] = p_c[6];
  c_strana[1] = p_c[3];
  c_strana[2] = p_c[0];
  c_strana[3] = p_c[7];
  c_strana[4] = p_c[4];
  c_strana[5] = p_c[1];
  c_strana[6] = p_c[8];
  c_strana[7] = p_c[5];
  c_strana[8] = p_c[2];





}

void leva() { //otočí pravou stranou nahoru, přepíše stav kostky



  char p_zl[9];
  char p_m[9];
  char p_b[9];
  char p_z[9];
  char p_o[9];

  for (int i = 0; i < 9; i++) {

    p_zl[i] = y_strana[i];
    p_m[i] = m_strana[i];
    p_b[i] = b_strana[i];
    p_z[i] = z_strana[i];
    p_o[i] = o_strana[i];

  }


  y_strana[2] = p_m[6];
  y_strana[5] = p_m[3];
  y_strana[8] = p_m[0];

  z_strana[2] = p_zl[2];
  z_strana[5] = p_zl[5];
  z_strana[8] = p_zl[8];

  b_strana[0] = p_z[2];
  b_strana[1] = p_z[5];
  b_strana[2] = p_z[8];

  m_strana[6] = p_b[0];
  m_strana[3] = p_b[1];
  m_strana[0] = p_b[2];

  o_strana[0] = p_o[6];
  o_strana[1] = p_o[3];
  o_strana[2] = p_o[0];
  o_strana[3] = p_o[7];
  o_strana[4] = p_o[4];
  o_strana[5] = p_o[1];
  o_strana[6] = p_o[8];
  o_strana[7] = p_o[5];
  o_strana[8] = p_o[2];






}
void leva_z() { //otočí pravou stranou dolu, přepíše stav kostky



  char p_zl[9];
  char p_m[9];
  char p_b[9];
  char p_z[9];
  char p_o[9];

  for (int i = 0; i < 9; i++) {

    p_zl[i] = y_strana[i];
    p_m[i] = m_strana[i];
    p_b[i] = b_strana[i];
    p_z[i] = z_strana[i];
    p_o[i] = o_strana[i];

  }


  y_strana[2] = p_z[2];
  y_strana[5] = p_z[5];
  y_strana[8] = p_z[8];

  z_strana[2] = p_b[0];
  z_strana[5] = p_b[1];
  z_strana[8] = p_b[2];

  b_strana[0] = p_m[6];
  b_strana[1] = p_m[3];
  b_strana[2] = p_m[0];

  m_strana[6] = p_zl[2];
  m_strana[3] = p_zl[5];
  m_strana[0] = p_zl[8];

  o_strana[0] = p_o[2];
  o_strana[1] = p_o[5];
  o_strana[2] = p_o[8];
  o_strana[3] = p_o[1];
  o_strana[4] = p_o[4];
  o_strana[5] = p_o[7];
  o_strana[6] = p_o[0];
  o_strana[7] = p_o[3];
  o_strana[8] = p_o[6];






}

void spodni() { //otočí spodní stranou doprava, přepíše stav kostky



  char p_c[9];
  char p_m[9];
  char p_b[9];
  char p_z[9];
  char p_o[9];

  for (int i = 0; i < 9; i++) {

    p_c[i] = c_strana[i];
    p_m[i] = m_strana[i];
    p_b[i] = b_strana[i];
    p_z[i] = z_strana[i];
    p_o[i] = o_strana[i];

  }


  m_strana[0] = p_o[0];
  m_strana[1] = p_o[1];
  m_strana[2] = p_o[2];

  c_strana[0] = p_m[0];
  c_strana[1] = p_m[1];
  c_strana[2] = p_m[2];

  z_strana[0] = p_c[0];
  z_strana[1] = p_c[1];
  z_strana[2] = p_c[2];

  o_strana[0] = p_z[0];
  o_strana[1] = p_z[1];
  o_strana[2] = p_z[2];

  b_strana[0] = p_b[2];
  b_strana[1] = p_b[5];
  b_strana[2] = p_b[8];
  b_strana[3] = p_b[1];
  b_strana[4] = p_b[4];
  b_strana[5] = p_b[7];
  b_strana[6] = p_b[0];
  b_strana[7] = p_b[3];
  b_strana[8] = p_b[6];





}

void spodni_z() { //otočí spodní stranou doleva, přepíše stav kostky



  char p_c[9];
  char p_m[9];
  char p_b[9];
  char p_z[9];
  char p_o[9];

  for (int i = 0; i < 9; i++) {

    p_c[i] = c_strana[i];
    p_m[i] = m_strana[i];
    p_b[i] = b_strana[i];
    p_z[i] = z_strana[i];
    p_o[i] = o_strana[i];

  }


  m_strana[0] = p_c[0];
  m_strana[1] = p_c[1];
  m_strana[2] = p_c[2];

  c_strana[0] = p_z[0];
  c_strana[1] = p_z[1];
  c_strana[2] = p_z[2];

  z_strana[0] = p_o[0];
  z_strana[1] = p_o[1];
  z_strana[2] = p_o[2];

  o_strana[0] = p_m[0];
  o_strana[1] = p_m[1];
  o_strana[2] = p_m[2];

  b_strana[0] = p_b[6];
  b_strana[1] = p_b[3];
  b_strana[2] = p_b[0];
  b_strana[3] = p_b[7];
  b_strana[4] = p_b[4];
  b_strana[5] = p_b[1];
  b_strana[6] = p_b[8];
  b_strana[7] = p_b[5];
  b_strana[8] = p_b[2];





}

void horni() { //otočí horní stranou doprava, přepíše stav kostky



  char p_c[9];
  char p_m[9];
  char p_zl[9];
  char p_z[9];
  char p_o[9];

  for (int i = 0; i < 9; i++) {

    p_c[i] = c_strana[i];
    p_m[i] = m_strana[i];
    p_zl[i] = y_strana[i];
    p_z[i] = z_strana[i];
    p_o[i] = o_strana[i];

  }


  m_strana[6] = p_o[6];
  m_strana[7] = p_o[7];
  m_strana[8] = p_o[8];

  c_strana[6] = p_m[6];
  c_strana[7] = p_m[7];
  c_strana[8] = p_m[8];

  z_strana[6] = p_c[6];
  z_strana[7] = p_c[7];
  z_strana[8] = p_c[8];

  o_strana[6] = p_z[6];
  o_strana[7] = p_z[7];
  o_strana[8] = p_z[8];

  y_strana[0] = p_zl[6];
  y_strana[1] = p_zl[3];
  y_strana[2] = p_zl[0];
  y_strana[3] = p_zl[7];
  y_strana[4] = p_zl[4];
  y_strana[5] = p_zl[1];
  y_strana[6] = p_zl[8];
  y_strana[7] = p_zl[5];
  y_strana[8] = p_zl[2];






}


void horni_z() { //otočí horní stranou doleva, přepíše stav kostky



  char p_c[9];
  char p_m[9];
  char p_zl[9];
  char p_z[9];
  char p_o[9];

  for (int i = 0; i < 9; i++) {

    p_c[i] = c_strana[i];
    p_m[i] = m_strana[i];
    p_zl[i] = y_strana[i];
    p_z[i] = z_strana[i];
    p_o[i] = o_strana[i];

  }


  m_strana[6] = p_c[6];
  m_strana[7] = p_c[7];
  m_strana[8] = p_c[8];

  c_strana[6] = p_z[6];
  c_strana[7] = p_z[7];
  c_strana[8] = p_z[8];

  z_strana[6] = p_o[6];
  z_strana[7] = p_o[7];
  z_strana[8] = p_o[8];

  o_strana[6] = p_m[6];
  o_strana[7] = p_m[7];
  o_strana[8] = p_m[8];

  y_strana[0] = p_zl[2];
  y_strana[1] = p_zl[5];
  y_strana[2] = p_zl[8];
  y_strana[3] = p_zl[1];
  y_strana[4] = p_zl[4];
  y_strana[5] = p_zl[7];
  y_strana[6] = p_zl[0];
  y_strana[7] = p_zl[3];
  y_strana[8] = p_zl[6];






}

void predni() { //otočí přední stranou doprava, přepíše stav kostky



  char p_m[9];
  char p_c[9];
  char p_zl[9];
  char p_o[9];
  char p_b[9];

  for (int i = 0; i < 9; i++) {

    p_m[i] = m_strana[i];
    p_c[i] = c_strana[i];
    p_zl[i] = y_strana[i];
    p_o[i] = o_strana[i];
    p_b[i] = b_strana[i];

  }


  c_strana[0] = p_b[0];
  c_strana[3] = p_b[3];
  c_strana[6] = p_b[6];

  y_strana[6] = p_c[0];
  y_strana[7] = p_c[3];
  y_strana[8] = p_c[6];

  o_strana[8] = p_zl[6];
  o_strana[5] = p_zl[7];
  o_strana[2] = p_zl[8];

  b_strana[0] = p_o[8];
  b_strana[3] = p_o[5];
  b_strana[6] = p_o[2];

  m_strana[0] = p_m[6];
  m_strana[1] = p_m[3];
  m_strana[2] = p_m[0];
  m_strana[3] = p_m[7];
  m_strana[4] = p_m[4];
  m_strana[5] = p_m[1];
  m_strana[6] = p_m[8];
  m_strana[7] = p_m[5];
  m_strana[8] = p_m[2];






}

void predni_z() { //otočí přední stranou doleva, přepíše stav kostky



  char p_m[9];
  char p_c[9];
  char p_zl[9];
  char p_o[9];
  char p_b[9];

  for (int i = 0; i < 9; i++) {

    p_m[i] = m_strana[i];
    p_c[i] = c_strana[i];
    p_zl[i] = y_strana[i];
    p_o[i] = o_strana[i];
    p_b[i] = b_strana[i];

  }


  c_strana[0] = p_zl[6];
  c_strana[3] = p_zl[7];
  c_strana[6] = p_zl[8];

  y_strana[6] = p_o[8];
  y_strana[7] = p_o[5];
  y_strana[8] = p_o[2];

  o_strana[8] = p_b[0];
  o_strana[5] = p_b[3];
  o_strana[2] = p_b[6];

  b_strana[0] = p_c[0];
  b_strana[3] = p_c[3];
  b_strana[6] = p_c[6];

  m_strana[0] = p_m[2];
  m_strana[1] = p_m[5];
  m_strana[2] = p_m[8];
  m_strana[3] = p_m[1];
  m_strana[4] = p_m[4];
  m_strana[5] = p_m[7];
  m_strana[6] = p_m[0];
  m_strana[7] = p_m[3];
  m_strana[8] = p_m[6];






}





void zadni() { //otočí zadní stranou doprava, přepíše stav kostky



  char p_z[9];
  char p_c[9];
  char p_zl[9];
  char p_o[9];
  char p_b[9];

  for (int i = 0; i < 9; i++) {

    p_z[i] = z_strana[i];
    p_c[i] = c_strana[i];
    p_zl[i] = y_strana[i];
    p_o[i] = o_strana[i];
    p_b[i] = b_strana[i];

  }


  c_strana[2] = p_b[2];
  c_strana[5] = p_b[5];
  c_strana[8] = p_b[8];

  y_strana[0] = p_c[2];
  y_strana[1] = p_c[5];
  y_strana[2] = p_c[8];

  o_strana[6] = p_zl[0];
  o_strana[3] = p_zl[1];
  o_strana[0] = p_zl[2];

  b_strana[2] = p_o[6];
  b_strana[5] = p_o[3];
  b_strana[8] = p_o[0];

  z_strana[0] = p_z[2];
  z_strana[1] = p_z[5];
  z_strana[2] = p_z[8];
  z_strana[3] = p_z[1];
  z_strana[4] = p_z[4];
  z_strana[5] = p_z[7];
  z_strana[6] = p_z[0];
  z_strana[7] = p_z[3];
  z_strana[8] = p_z[6];






}

void zadni_z() { //otočí zadní stranou doleva, přepíše stav kostky



  char p_z[9];
  char p_c[9];
  char p_zl[9];
  char p_o[9];
  char p_b[9];

  for (int i = 0; i < 9; i++) {

    p_z[i] = z_strana[i];
    p_c[i] = c_strana[i];
    p_zl[i] = y_strana[i];
    p_o[i] = o_strana[i];
    p_b[i] = b_strana[i];

  }


  c_strana[2] = p_zl[0];
  c_strana[5] = p_zl[1];
  c_strana[8] = p_zl[2];

  y_strana[0] = p_o[6];
  y_strana[1] = p_o[3];
  y_strana[2] = p_o[0];

  o_strana[6] = p_b[2];
  o_strana[3] = p_b[5];
  o_strana[0] = p_b[8];

  b_strana[2] = p_c[2];
  b_strana[5] = p_c[5];
  b_strana[8] = p_c[8];

  z_strana[0] = p_z[6];
  z_strana[1] = p_z[3];
  z_strana[2] = p_z[0];
  z_strana[3] = p_z[7];
  z_strana[4] = p_z[4];
  z_strana[5] = p_z[1];
  z_strana[6] = p_z[8];
  z_strana[7] = p_z[5];
  z_strana[8] = p_z[2];






}
void zandej_nahoru() {

  if ( y_strana[1] == 'b' &&  y_strana[5] == 'b' &&  y_strana[7] == 'b' &&  y_strana[3] == 'b') {

    Serial.println("Bylo zandáno nahoru");
    stav_kostky();
    progres = 2;

  }
  else if (progres == 1) {


    if (b_strana[3] == 'b') {

      for (int i = 0; i < 4; i ++) {

        if (y_strana[7] != 'b') {

          predni();
          predni();
          i = 4;

        }
        else {

          horni();
        }

      }

    }

    else if (b_strana[7] == 'b') {

      for (int i = 0; i < 4; i ++) {

        if (y_strana[3] != 'b') {

          prava();
          prava();
          i = 4;

        }
        else {

          horni();
        }

      }

    }
    else if (b_strana[5] == 'b') {

      for (int i = 0; i < 4; i ++) {

        if (y_strana[1] != 'b') {

          zadni();
          zadni();
          i = 4;

        }
        else {

          horni();
        }

      }

    }
    else if (b_strana[1] == 'b') {

      for (int i = 0; i < 4; i ++) {

        if (y_strana[5] != 'b') {

          leva();
          leva();
          i = 4;

        }
        else {

          horni();
        }

      }

    }
    else if (m_strana[1] == 'b') {

      for (int i = 0; i < 4; i ++) {

        if (y_strana[5] != 'b') {

          predni_z();
          leva();
          i = 4;

        }
        else {

          horni();
        }

      }

    }

    else if (m_strana[3] == 'b') {

      for (int i = 0; i < 4; i ++) {

        if (y_strana[5] != 'b') {

          leva();
          i = 4;

        }
        else {

          horni();
        }

      }

    }

    else if (m_strana[5] == 'b') {

      for (int i = 0; i < 4; i ++) {

        if (y_strana[3] != 'b') {

          prava();
          i = 4;

        }
        else {

          horni();
        }

      }

    }

    else if (m_strana[7] == 'b') {

      for (int i = 0; i < 4; i ++) {

        if (y_strana[5] != 'b') {
          predni();
          leva();
          i = 4;

        }
        else {

          horni();
        }

      }

    }

    else if (c_strana[1] == 'b') {

      for (int i = 0; i < 4; i ++) {

        if (y_strana[7] != 'b') {

          prava();
          predni();
          i = 4;

        }
        else {

          horni();
        }

      }

    }
    else if (c_strana[3] == 'b') {

      for (int i = 0; i < 4; i ++) {

        if (y_strana[7] != 'b') {

          predni();
          i = 4;

        }
        else {

          horni();
        }

      }

    }
    else if (c_strana[7] == 'b') {

      for (int i = 0; i < 4; i ++) {

        if (y_strana[7] != 'b') {

          prava_z();
          predni();
          i = 4;

        }
        else {

          horni();
        }

      }

    }
    else if (c_strana[5] == 'b') {

      for (int i = 0; i < 4; i ++) {

        if (y_strana[1] != 'b') {

          zadni();
          i = 4;

        }
        else {

          horni();
        }

      }

    }
    else if (z_strana[1] == 'b') {

      for (int i = 0; i < 4; i ++) {

        if (y_strana[3] != 'b') {

          zadni();
          prava_z();
          i = 4;

        }
        else {

          horni();
        }

      }

    }
    else if (z_strana[3] == 'b') {

      for (int i = 0; i < 4; i ++) {

        if (y_strana[3] != 'b') {

          prava_z();
          i = 4;

        }
        else {

          horni();
        }

      }

    }
    else if (z_strana[7] == 'b') {

      for (int i = 0; i < 4; i ++) {

        if (y_strana[3] != 'b') {

          zadni_z();
          prava_z();
          i = 4;

        }
        else {

          horni();
        }

      }

    }
    else if (z_strana[5] == 'b') {

      for (int i = 0; i < 4; i ++) {

        if (y_strana[5] != 'b') {

          leva_z();
          i = 4;

        }
        else {

          horni();
        }

      }

    }
    else if (o_strana[1] == 'b') {

      for (int i = 0; i < 4; i ++) {

        if (y_strana[1] != 'b') {

          leva_z();
          zadni_z();
          i = 4;

        }
        else {

          horni();
        }

      }

    }
    else if (o_strana[3] == 'b') {

      for (int i = 0; i < 4; i ++) {

        if (y_strana[1] != 'b') {

          zadni_z();
          i = 4;

        }
        else {

          horni();
        }

      }

    }
    else if (o_strana[5] == 'b') {

      for (int i = 0; i < 4; i ++) {

        if (y_strana[1] != 'b') {

          predni_z();
          i = 4;

        }
        else {

          horni();
        }

      }

    }
    else if (o_strana[7] == 'b') {

      for (int i = 0; i < 4; i ++) {

        if (y_strana[1] != 'b') {
          leva();
          zadni_z();
          i = 4;

        }
        else {

          horni();
        }

      }

    }






  }
}

void zandej_bily_kriz() {
  if (m_strana[1] == 'm' && c_strana[1] == 'c' && z_strana[1] == 'z' && o_strana[1] == 'o' && b_strana[1] == 'b' && b_strana[3] == 'b' && b_strana[5] == 'b' && b_strana[7] == 'b') {

    Serial.println("Kriz slozen");
    stav_kostky();
    progres = 3;

  }
  else if (progres == 2) {

    if (y_strana[7] == 'b') {

      zandej_kriz_dolu(m_strana[7]);
    }
    else if (y_strana[3] == 'b') {

      zandej_kriz_dolu(c_strana[7]);
    }
    else if (y_strana[1] == 'b') {
      zandej_kriz_dolu(z_strana[7]);
    }
    else if (y_strana[5] == 'b') {
      zandej_kriz_dolu(o_strana[7]);
    }




  }


}
void zandej_kriz_dolu(char barva) {
  Serial.println(barva);
  if (barva == 'm') {

    for (int i = 0; i < 5; i++) {

      if (m_strana[7] == 'm' && y_strana[7] == 'b') {

        predni();
        predni();
        i = 5;

      }
      else {

        horni();

      }
    }
  }
  else if (barva == 'c') {

    for (int i = 0; i < 5; i++) {

      if (c_strana[7] == 'c' && y_strana[3] == 'b') {

        prava_z();
        prava_z();
        Serial.println(b_strana[3]);

        i = 5;

      }
      else {

        horni();

      }
    }
  }
  else if (barva == 'z') {

    for (int i = 0; i < 5; i++) {

      if (z_strana[7] == 'z' && y_strana[1] == 'b') {

        zadni();
        zadni();

        i = 5;

      }
      else {

        horni();

      }
    }
  }
  else if (barva == 'o') {

    for (int i = 0; i < 5; i++) {

      if (o_strana[7] == 'o' && y_strana[5] == 'b') {

        leva();
        leva();

        i = 5;

      }
      else {

        horni();

      }
    }
  }

}

void pridej_rohy() {


  if (b_strana[6] == 'b' && b_strana[8] == 'b' && b_strana[2] == 'b' && b_strana[0] == 'b' && m_strana[0] == 'm' && m_strana[2] == 'm' && c_strana[0] == 'c' && c_strana[2] == 'c' && z_strana[0] == 'z' && z_strana[2] == 'z' && o_strana[0] == 'o' && o_strana[2] == 'o') {


    Serial.println("Spodni vrstva hotova");
    stav_kostky();
    progres = 4;


  }
  else if (progres == 3) {

    if (b_strana[6] == 'b' && m_strana[2] != 'm' && c_strana[0] != 'c') {


      prava();
      horni_z();
      prava_z();
      zandej_roh_p(y_strana[8], m_strana[6]);



    }
    else if (b_strana[0] == 'b' && m_strana[0] != 'm' && o_strana[2] != 'o') {


      predni_z();
      horni_z();
      predni();
      zandej_roh_p(y_strana[2], o_strana[6]);

    }
    else if (b_strana[2] == 'b' && o_strana[0] != 'o' && z_strana[2] != 'z') {


      leva_z();
      horni_z();
      leva();
      zandej_roh_p(y_strana[0], z_strana[6]);

    }
    else if (b_strana[8] == 'b' && z_strana[0] != 'z' && c_strana[2] != 'c') {


      zadni();
      horni_z();
      zadni_z();
      zandej_roh_p(y_strana[6], c_strana[6]);

    }
    else if (m_strana[2] == 'b' || c_strana[0] == 'b') {

      otoc_roh(1);

    }
    else if (c_strana[2] == 'b' || z_strana[0] == 'b') {

      otoc_roh(2);
    }
    else if (z_strana[2] == 'b' || o_strana[0] == 'b') {

      otoc_roh(3);
    }
    else if (o_strana[2] == 'b' || m_strana[0] == 'b') {

      otoc_roh(4);
    }
    else if (m_strana[8] == 'b') {

      zandej_roh_p(y_strana[6], c_strana[6]);
    }
    else if (c_strana[8] == 'b') {

      zandej_roh_p(y_strana[0], z_strana[6]);
    }
    else if (z_strana[8] == 'b') {

      zandej_roh_p(y_strana[2], o_strana[6]);
    }
    else if (o_strana[8] == 'b') {

      zandej_roh_p(y_strana[8], m_strana[6]);
    }
    else if (m_strana[6] == 'b') {

      zandej_roh_l(y_strana[8], o_strana[8]);
    }
    else if (o_strana[6] == 'b') {

      zandej_roh_l(y_strana[2], z_strana[8]);
    }
    else if (z_strana[6] == 'b') {

      zandej_roh_l(y_strana[0], c_strana[8]);
    }
    else if (c_strana[6] == 'b') {

      zandej_roh_l(y_strana[6], m_strana[8]);
    }
    else if (y_strana[0] == 'b') {

      bily_hor_n_y(c_strana[8]);

    }
    else if (y_strana[2] == 'b') {

      bily_hor_n_y(z_strana[8]);

    }
    else if (y_strana[8] == 'b') {

      bily_hor_n_y(o_strana[8]);

    }
    else if (y_strana[6] == 'b') {

      bily_hor_n_y(m_strana[8]);

    }


  }



}

void bily_hor_n_y(char barva) {

  if (barva == 'm') {

    for (int i = 0; i < 5; i ++) {

      if (z_strana[8] == 'm' && y_strana[2] == 'b') {

        predni_z();
        horni();
        predni();
        i = 5;
      }
      else {

        horni();
      }


    }
  }
  if (barva == 'z') {

    for (int i = 0; i < 5; i ++) {

      if (m_strana[8] == 'z' && y_strana[6] == 'b') {

        zadni();
        horni();
        zadni_z();
        i = 5;
      }
      else {

        horni();
      }


    }
  }
  if (barva == 'o') {

    for (int i = 0; i < 5; i ++) {

      if (c_strana[8] == 'o' && y_strana[0] == 'b') {

        leva_z();
        horni();
        leva();
        i = 5;
      }
      else {

        horni();
      }


    }
  }
  if (barva == 'c') {

    for (int i = 0; i < 5; i ++) {

      if (o_strana[8] == 'c' && y_strana[8] == 'b') {

        prava();
        horni();
        prava_z();
        i = 5;
      }
      else {

        horni();
      }


    }
  }



}

void otoc_roh(int pripad) {

  if (pripad == 1) {

    while (b_strana[6] != 'b') {

      prava();
      horni_z();
      prava_z();
      horni();

    }


  }
  else if (pripad == 2) {

    while (b_strana[8] != 'b') {

      zadni();
      horni_z();
      zadni_z();
      horni();
    }

  }
  else if (pripad == 3) {

    while (b_strana[2] != 'b') {

      leva_z();
      horni_z();
      leva();
      horni();
    }

  }
  else if (pripad == 4) {

    while (b_strana[0] != 'b') {

      leva();
      horni_z();
      leva_z();
      horni();
    }

  }

}

void zandej_roh_p(char barva1, char barva2) {

  if (barva1 == 'm' && barva2 == 'c') {

    for (int i = 0; i < 5; i++) {

      if (y_strana[8] == 'm' && m_strana[6] == 'c' && o_strana[8] == 'b') {

        prava();
        horni();
        prava_z();
        i = 5;
      }
      else {
        horni();

      }
    }

  }
  if (barva1 == 'o' && barva2 == 'm') {

    for (int i = 0; i < 5; i++) {

      if (y_strana[2] == 'o' && o_strana[6] == 'm' && z_strana[8] == 'b') {

        predni_z();
        horni();
        predni();
        i = 5;
      }
      else {
        horni();

      }
    }

  }
  if (barva1 == 'z' && barva2 == 'o') {

    for (int i = 0; i < 5; i++) {

      if (y_strana[0] == 'z' && z_strana[6] == 'o' && c_strana[8] == 'b') {

        leva_z();
        horni();
        leva();
        i = 5;
      }
      else {
        horni();

      }
    }

  }
  if (barva1 == 'c' && barva2 == 'z') {

    for (int i = 0; i < 5; i++) {

      if (y_strana[6] == 'c' && c_strana[6] == 'z' && m_strana[8] == 'b') {

        zadni();
        horni();
        zadni_z();
        i = 5;
      }
      else {
        horni();

      }
    }

  }


}



void zandej_roh_l(char barva1, char barva2) {

  if (barva1 == 'c' && barva2 == 'm') {

    for (int i = 0; i < 5; i++) {

      if (y_strana[0] == 'c' && c_strana[8] == 'm' && z_strana[6] == 'b') {

        predni();
        horni_z();
        predni_z();
        i = 5;
      }
      else {
        horni();

      }
    }

  }
  if (barva1 == 'z' && barva2 == 'c') {

    for (int i = 0; i < 5; i++) {

      if (y_strana[2] == 'z' && z_strana[8] == 'c' && o_strana[6] == 'b') {

        prava_z();
        horni_z();
        prava();
        i = 5;
      }
      else {
        horni();

      }
    }

  }
  if (barva1 == 'o' && barva2 == 'z') {

    for (int i = 0; i < 5; i++) {

      if (y_strana[8] == 'o' && o_strana[8] == 'z' && m_strana[6] == 'b') {

        zadni_z();
        horni_z();
        zadni();
        i = 5;
      }
      else {
        horni();

      }
    }

  }
  if (barva1 == 'm' && barva2 == 'o') {

    for (int i = 0; i < 5; i++) {

      if (y_strana[6] == 'm' && m_strana[8] == 'o' && c_strana[7] == 'b') {

        leva();
        horni_z();
        leva_z();
        i = 5;
      }
      else {
        horni();

      }
    }

  }


}


void pridej_hrany() {


  if ( m_strana[3] == 'm' && m_strana[5] == 'm' && c_strana[3] == 'c' && c_strana[5] == 'c' && z_strana[3] == 'z' && z_strana[5] == 'z' && o_strana[3] == 'o' && o_strana[5] == 'o') {

    Serial.println("Bocni hrany pridany");
    stav_kostky();
    progres = 5;


  }
  else if (progres == 4) {


    if (c_strana[3] != 'c' && m_strana[5] != 'm' && c_strana[3] != 'y' && m_strana[5] != 'y' ) {




      prava();
      horni();
      prava_z();
      horni();
      predni();
      horni_z();
      predni_z();
      rozhodni_kam_roh(y_strana[1], z_strana[7]);



    }
    else if (z_strana[3] != 'z' && c_strana[5] != 'c' && z_strana[3] != 'y' && c_strana[5] != 'y' ) {




      zadni();
      horni();
      zadni_z();
      horni();
      prava_z();
      horni_z();
      prava();
      rozhodni_kam_roh(y_strana[5], o_strana[7]);



    }
    else if (o_strana[3] != 'o' && z_strana[5] != 'z' && o_strana[3] != 'y' && z_strana[5] != 'y' ) {




      leva_z();
      horni();
      leva();
      horni();
      zadni_z();
      horni_z();
      zadni();
      rozhodni_kam_roh(y_strana[7], m_strana[7]);



    }

    else if (m_strana[3] != 'm' && o_strana[5] != 'o' && m_strana[3] != 'y' && o_strana[5] != 'y' ) {




      leva();
      horni_z();
      leva_z();
      horni_z();
      predni_z();
      horni();
      predni();
      rozhodni_kam_roh(y_strana[7], m_strana[7]);



    }
    else if (m_strana[7] != 'y' && y_strana[7] != 'y') {


      rozhodni_kam_roh(y_strana[7], m_strana[7]);

    }
    else if (c_strana[7] != 'y' && y_strana[3] != 'y') {


      rozhodni_kam_roh(y_strana[3], c_strana[7]);

    }
    else if (z_strana[7] != 'y' && y_strana[1] != 'y') {


      rozhodni_kam_roh(y_strana[1], z_strana[7]);

    }
    else if (o_strana[7] != 'y' && y_strana[5] != 'y') {


      rozhodni_kam_roh(y_strana[5], o_strana[7]);

    }



  }





}
void rozhodni_kam_roh(char barva_hor, char barva_dol) {

  if (barva_hor == 'm' && barva_dol == 'c') {

    for (int i = 0; i < 5; i ++) {

      if (z_strana[7] == 'c' && y_strana[1] == 'm') {

        predni();
        horni_z();
        predni_z();
        horni_z();
        prava();
        horni();
        prava_z();
        i = 5;

      }
      else {

        horni();
      }

    }

  }
  else if (barva_hor == 'c' && barva_dol == 'm') {

    for (int i = 0; i < 5; i ++) {

      if (o_strana[7] == 'm' && y_strana[5] == 'c') {

        prava();
        horni();
        prava_z();
        horni();
        predni();
        horni_z();
        predni_z();
        i = 5;

      }
      else {

        horni();
      }

    }

  }
  else if (barva_hor == 'c' && barva_dol == 'z') {

    for (int i = 0; i < 5; i ++) {

      if (o_strana[7] == 'z' && y_strana[5] == 'c') {

        prava_z();
        horni_z();
        prava();
        horni_z();
        zadni();
        horni();
        zadni_z();
        i = 5;

      }
      else {

        horni();
      }

    }

  }
  else if (barva_hor == 'z' && barva_dol == 'c') {

    for (int i = 0; i < 5; i ++) {

      if (m_strana[7] == 'c' && y_strana[7] == 'z') {

        zadni();
        horni();
        zadni_z();
        horni();
        prava_z();
        horni_z();
        prava();
        i = 5;

      }
      else {

        horni();
      }

    }

  }
  else if (barva_hor == 'z' && barva_dol == 'o') {

    for (int i = 0; i < 5; i ++) {

      if (m_strana[7] == 'o' && y_strana[7] == 'z') {

        zadni_z();
        horni_z();
        zadni();
        horni_z();
        leva_z();
        horni();
        leva();
        i = 5;

      }
      else {

        horni();
      }

    }

  }
  else if (barva_hor == 'o' && barva_dol == 'z') {

    for (int i = 0; i < 5; i ++) {

      if (c_strana[7] == 'z' && y_strana[3] == 'o') {

        leva_z();
        horni();
        leva();
        horni();
        zadni_z();
        horni_z();
        zadni();
        i = 5;

      }
      else {

        horni();
      }

    }

  }
  else if (barva_hor == 'o' && barva_dol == 'm') {

    for (int i = 0; i < 5; i ++) {

      if (c_strana[7] == 'm' && y_strana[3] == 'o') {

        leva();
        horni_z();
        leva_z();
        horni_z();
        predni_z();
        horni();
        predni();
        i = 5;

      }
      else {

        horni();
      }

    }

  }
  else if (barva_hor == 'm' && barva_dol == 'o') {

    for (int i = 0; i < 5; i ++) {

      if (z_strana[7] == 'o' && y_strana[1] == 'm') {

        predni_z();
        horni();
        predni();
        horni();
        leva();
        horni_z();
        leva_z();
        i = 5;

      }
      else {

        horni();
      }

    }

  }



}
void sloz_zluty_kriz() {


  if (y_strana[1] == 'y' && y_strana[3] == 'y' && y_strana[5] == 'y' && y_strana[7] == 'y') {

    Serial.print("Zluty kriz slozen");
    stav_kostky();
    progres = 6;

  }
  else if (progres == 5) {

    if (y_strana[1] == 'y' && y_strana[3] != 'y' && y_strana[5] == 'y' && y_strana[7] != 'y') {

      predni_z();
      prava();
      horni_z();
      prava_z();
      horni();
      prava();
      horni_z();
      prava_z();
      horni();
      predni();
    }
    else if (y_strana[1] != 'y' && y_strana[3] != 'y' && y_strana[5] == 'y' && y_strana[7] == 'y') {

      horni_z();
      predni_z();
      prava();
      horni_z();
      prava_z();
      horni();
      prava();
      horni_z();
      prava_z();
      horni();
      predni();

    }
    else if (y_strana[1] != 'y' && y_strana[3] == 'y' && y_strana[5] != 'y' && y_strana[7] == 'y') {

      horni_z();
      horni_z();
      predni_z();
      prava();
      horni_z();
      prava_z();
      horni();
      prava();
      horni_z();
      prava_z();
      horni();
      predni();

    }
    else if (y_strana[1] == 'y' && y_strana[3] == 'y' && y_strana[5] != 'y' && y_strana[7] != 'y') {

      horni();
      predni_z();
      prava();
      horni_z();
      prava_z();
      horni();
      prava();
      horni_z();
      prava_z();
      horni();
      predni();

    }
    else if (y_strana[1] != 'y' && y_strana[3] == 'y' && y_strana[5] == 'y' && y_strana[7] != 'y') {

      predni_z();
      prava();
      horni_z();
      prava_z();
      horni();
      predni();

    }
    else if (y_strana[1] == 'y' && y_strana[3] != 'y' && y_strana[5] != 'y' && y_strana[7] == 'y') {
      horni();
      predni_z();
      prava();
      horni_z();
      prava_z();
      horni();
      predni();

    }
    else if (y_strana[1] != 'y' && y_strana[3] != 'y' && y_strana[5] != 'y' && y_strana[7] != 'y') {
      predni_z();
      prava();
      horni_z();
      prava_z();
      horni();
      prava();
      horni_z();
      prava_z();
      horni();
      predni();
      horni();
      predni_z();
      prava();
      horni_z();
      prava_z();
      horni();
      predni();


    }




  }



}
void modra_h_nam() {


  for (int i = 0; i < 5; i++) {

    if (m_strana[7] == 'm') {

      Serial.println("Modra hrana na miste");
      stav_kostky();
      i = 5;
      progres = 7;
    }
    else {

      horni();

    }




  }
}

void oprav_hrany() {

  if (m_strana[7] == 'm' && o_strana[7] == 'o' && c_strana[7] == 'c' && z_strana[7] == 'z') {


    Serial.println("Zluty kriz opraven");
    stav_kostky();
    progres = 8;

  }
  else if (progres = 7) {


    if (o_strana[7] == 'c' && z_strana[7] == 'o') {

      prava();
      horni_z();
      prava_z();
      horni_z();
      prava();
      horni_z();
      horni_z();
      prava_z();


    }
    else if (o_strana[7] == 'c' && z_strana[7] == 'z') {

      prava();
      horni_z();
      prava_z();
      horni_z();
      prava();
      horni_z();
      horni_z();
      prava_z();
      horni();
      prava();
      horni_z();
      prava_z();
      horni_z();
      prava();
      horni_z();
      horni_z();
      prava_z();
      horni();
      horni();


    }
    else if (o_strana[7] == 'o' && z_strana[7] == 'c') {

      horni();
      horni();
      prava();
      horni_z();
      prava_z();
      horni_z();
      prava();
      horni_z();
      horni_z();
      prava_z();
      horni();


    }
    else if (o_strana[7] == 'z' && z_strana[7] == 'o') {

      horni();
      prava();
      horni_z();
      prava_z();
      horni_z();
      prava();
      horni_z();
      horni_z();
      prava_z();
      horni_z();
      horni_z();


    }
    else if (o_strana[7] == 'z' && z_strana[7] == 'c') {

      horni_z();
      prava();
      horni_z();
      prava_z();
      horni_z();
      prava();
      horni_z();
      horni_z();
      prava_z();
      horni_z();


    }


  }


}



void zandej_spravne_barvy() {


  if (rohy == true) {

    Serial.println("Barvy jsou na svem miste");
    stav_kostky();
    progres = 9;

  }
  else if (progres == 8) {

    if (m_strana[8] == 'm' && c_strana[6] == 'c' && y_strana[6] == 'y') {

      pripad(1);

    }
    else if (m_strana[8] == 'c' && c_strana[6] == 'y' && y_strana[6] == 'm') {

      pripad(1);

    }
    else if (m_strana[8] == 'y' && c_strana[6] == 'm' && y_strana[6] == 'c') {

      pripad(1);

    }
    else if (c_strana[8] == 'c' && z_strana[6] == 'z' && y_strana[0] == 'y') {

      pripad(2);

    }
    else if (c_strana[8] == 'z' && z_strana[6] == 'y' && y_strana[0] == 'c') {

      pripad(2);

    }
    else if (c_strana[8] == 'y' && z_strana[6] == 'c' && y_strana[0] == 'z') {

      pripad(2);

    }
    else if (z_strana[8] == 'z' && o_strana[6] == 'o' && y_strana[2] == 'y') {

      pripad(3);

    }
    else if (z_strana[8] == 'o' && o_strana[6] == 'y' && y_strana[2] == 'z') {

      pripad(3);

    }
    else if (z_strana[8] == 'y' && o_strana[6] == 'z' && y_strana[2] == 'o') {

      pripad(3);

    }
    else if (o_strana[8] == 'o' && m_strana[6] == 'm' && y_strana[8] == 'y') {

      pripad(4);

    }
    else if (o_strana[8] == 'm' && m_strana[6] == 'y' && y_strana[8] == 'o') {

      pripad(4);

    }
    else if (o_strana[8] == 'y' && m_strana[6] == 'o' && y_strana[8] == 'm') {

      pripad(4);

    }


  }





}

void pripad(int pr) {

  if (pr == 1) {

    for (int i = 0; i < 4; i ++) {

      if (m_strana[6] == 'm' && o_strana[8] == 'o' && y_strana[8] == 'y') {

        rohy = true;
        i = 4;

      }
      else if (m_strana[6] == 'y' && o_strana[8] == 'm' && y_strana[8] == 'o') {

        rohy = true;
        i = 4;
      }
      else if (m_strana[6] == 'o' && o_strana[8] == 'y' && y_strana[8] == 'm') {

        rohy = true;
        i = 4;
      }
      else {

        horni_z();
        prava();
        horni();
        leva();
        horni_z();
        prava_z();
        horni();
        leva_z();

      }


    }



  }
  if (pr == 2) {

    for (int i = 0; i < 4; i ++) {

      if (m_strana[6] == 'm' && o_strana[8] == 'o' && y_strana[8] == 'y') {

        rohy = true;
        i = 4;

      }
      else if (m_strana[6] == 'y' && o_strana[8] == 'm' && y_strana[8] == 'o') {

        rohy = true;
        i = 4;
      }
      else if (m_strana[6] == 'o' && o_strana[8] == 'y' && y_strana[8] == 'm') {

        rohy = true;
        i = 4;
      }
      else {

        horni_z();
        zadni();
        horni();
        predni();
        horni_z();
        zadni_z();
        horni();
        predni_z();

      }


    }



  }
  if (pr == 3) {

    for (int i = 0; i < 4; i ++) {

      if (m_strana[6] == 'm' && o_strana[8] == 'o' && y_strana[8] == 'y') {

        rohy = true;
        i = 4;

      }
      else if (m_strana[6] == 'y' && o_strana[8] == 'm' && y_strana[8] == 'o') {

        rohy = true;
        i = 4;
      }
      else if (m_strana[6] == 'o' && o_strana[8] == 'y' && y_strana[8] == 'm') {

        rohy = true;
        i = 4;
      }
      else {

        horni_z();
        leva_z();
        horni();
        prava_z();
        horni_z();
        leva();
        horni();
        prava();

      }


    }



  }
  if (pr == 4) {

    for (int i = 0; i < 4; i ++) {

      if (m_strana[8] == 'm' && c_strana[6] == 'c' && y_strana[6] == 'y') {

        rohy = true;
        i = 4;

      }
      else if (m_strana[8] == 'c' && c_strana[6] == 'y' && y_strana[6] == 'm') {

        rohy = true;
        i = 4;
      }
      else if (m_strana[8] == 'y' && c_strana[6] == 'm' && y_strana[6] == 'c') {

        rohy = true;
        i = 4;
      }
      else {

        horni_z();
        predni_z();
        horni();
        zadni_z();
        horni_z();
        predni();
        horni();
        zadni();

      }


    }



  }





}

void dokonci_vrsek() {

  if (y_strana[8] == 'y' && y_strana[6] == 'y' && y_strana[2] == 'y' && y_strana[0] == 'y') {
    modra_h_nam();
    Serial.println("Kostka je slozena, gratuluji");
    stav_kostky();
    progres = 10;

  }
  else if (progres == 9) {

    if (y_strana[6] == 'y') {

      horni();
    }
    else if (y_strana[6] != 'y') {

      for (int i = 0; i < 5; i++) {

        if (y_strana[6] == 'y') {

          horni();
        }
        else {

          prava_z();
          spodni_z();
          prava();
          spodni();
          prava_z();
          spodni_z();
          prava();
          spodni();

        }


      }

    }




  }



}



void progres_kostky() {

  switch (progres) {
    case 1:
      zandej_nahoru();
      break;
    case 2:
      zandej_bily_kriz();
      break;
    case 3:
      pridej_rohy();
      break;
    case 4:
      pridej_hrany();
      break;
    case 5:
      sloz_zluty_kriz();
      break;
    case 6:
      modra_h_nam();
      break;
    case 7:
      oprav_hrany();
      break;
    case 8:
      zandej_spravne_barvy();
      break;
    case 9:
      dokonci_vrsek();
      break;




  }




}
void sloz_kostku() {

  while (progres != 10) {

    progres_kostky();
  }
}






void stav_strany(char strana[])
{

  Serial.println("\r");
  Serial.print("Strana: ");
  Serial.println(strana[4]);

  for (int i = 0; i < 9; i = i + 3)
  {
    Serial.print("|");
    Serial.print(strana[i]);
    Serial.print("|");
    Serial.print(strana[i + 1]);
    Serial.print("|");
    Serial.print(strana[i + 2]);
    Serial.println("|");
  }
}

void stav_kostky() {

  stav_strany(b_strana);
  stav_strany(m_strana);
  stav_strany(c_strana);
  stav_strany(z_strana);
  stav_strany(o_strana);
  stav_strany(y_strana);



}



void setup() {

  s_rotace.attach(9);
  s_preklop.attach(10);
  s_rotace.write(rotace_poz);
  s_preklop.write(preklop_poz);
  delay(2000);
  Serial.begin(9600);
  while (! Serial);

}

void loop() {

  otoc_poz1();
  delay(10000);
  otoc_poz2();
  delay(10000);
  otoc_poz3();
  delay(10000);
  sloz_kostku();

}
