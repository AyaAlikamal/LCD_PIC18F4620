/* 
 * File:   application.c
 * Author: AyaAli
 * Created on September 22, 2023, 10:24 AM
 */
#include "application.h"
int main() {
 uint_8 lcd_Counter = 0;
 uint_8 lcd_text[4];
 uint_8 custom_1[] = {0x0E, 0X0A, 0x11, 0x11, 0X11,0x11,0x1F, 0x00};
 uint_8 custom_2[] = {0x0E, 0X0A, 0x11, 0x11, 0X11,0x1F,0x1F, 0x00};
Std_ReturnType ret = E_NOT_OK;
application_initialize();

//ret = lcd_4_bit_send_string_position(&lcd_1, 1,1,"Counter");
// ret = lcd_8_bit_send_string_position(&lcd_2, 1,1,"Loading");

while(1){  
     ret= lcd_8_bit_send_custom_char(&lcd_2,custom_1, 1, 20, 0);
     ret= lcd_4_bit_send_custom_char(&lcd_1,custom_2, 1, 20, 0);
//    welcome_massage();
//    loading_massage();
    ret = convert_uint_8_string(lcd_Counter,lcd_text);
    ret = lcd_4_bit_send_string_position(&lcd_1, 1,10,lcd_text);    
    __delay_ms(250);    
    lcd_Counter++;
//    for(lcd_Counter = 5 ; lcd_Counter<8 ; lcd_Counter++){
//    ret = lcd_8_bit_send_string_position(&lcd_2, 1,lcd_Counter,"Hello");
//    __delay_ms(250);
//     ret = lcd_8_bit_send_string_position(&lcd_2, 1,lcd_Counter,"     ");
//    }
//    ret = lcd_8_bit_send_string_position(&lcd_2, 1,5," ");
//for(lcd_Counter = 7 ; lcd_Counter<=5 ; lcd_Counter++){
//    ret = lcd_8_bit_send_string_position(&lcd_2, 1,lcd_Counter,"Hello");
//    __delay_ms(250);
//     ret = lcd_8_bit_send_string_position(&lcd_2, 1,lcd_Counter,"     ");
//    }
//    ret = lcd_8_bit_send_string_position(&lcd_2, 1,5," ");
 
}
 return (EXIT_SUCCESS);
}
void application_initialize(void){
   ECU_Layer_initialize();
  
}
void welcome_massage(void){
    uint_8 L_lcd1_counter = ZERO_INIT;
    for(L_lcd1_counter= 0 ; L_lcd1_counter<2 ; L_lcd1_counter++){
    lcd_8_bit_send_string_position(&lcd_2, 1,7,"Hello All");
    lcd_8_bit_send_string_position(&lcd_2, 2,4,"Embedded Course");
     __delay_ms(300);
    lcd_8_bit_send_command(&lcd_2, LCD_CLEAR);     
    __delay_ms(100);}
}

void loading_massage(void){
    uint_8 L_lcd2_counter = ZERO_INIT;
    lcd_4_bit_send_string_position(&lcd_1, 1,1,"Loading");
    for(L_lcd2_counter= 8 ; L_lcd2_counter<16 ; L_lcd2_counter++){
    lcd_4_bit_send_string_position(&lcd_1, 1,L_lcd2_counter,".");
     __delay_ms(300);
    lcd_8_bit_send_string_position(&lcd_2, 1,8,"        ");
    __delay_ms(100);}
}
