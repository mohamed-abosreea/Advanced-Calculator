/**
 * Author: Mohamed Abosreea
 * main.c
 * Created on: Aug 22, 2023
 */

#include "std_lib.h"
#include "std_types.h"
#include "TM4C123GH6PM.h"
#include "HAL/LCD/lcd.h"
#include "MCAL/GPIO/gpio.h"
#include "HAL/KEYPAD/keypad.h"
#include "calculator.h"

extern int flag ;

void main(void)
{
    gpioPortClkEnable(PORTF);
    gpioPortClkEnable(PORTB);
    gpioPortClkEnable(PORTE);
    gpioPortClkEnable(PORTA);
    gpioPortClkEnable(PORTC);
    pinConfig_t RS = {.port = PORTC,.pin = GPIO_PIN4 ,.direction = OUTPUT, .mode = DIO, .pinAttach = NO_ATTACH, .state = LOW, .pinOutCurrent = PIN_CURRENT_2mA};

    lcd_t lcd1 = {
                  .lcd_connection = _8_BIT,

                  .lcd_en.port = PORTC,
                  .lcd_en.pin = GPIO_PIN6,
                  .lcd_en.direction = OUTPUT,
                  .lcd_en.mode = DIO,
                  .lcd_en.pinAttach = NO_ATTACH,
                  .lcd_en.pinOutCurrent = PIN_CURRENT_2mA,
                  .lcd_en.state = LOW,

                  .lcd_rs.port = PORTC,
                  .lcd_rs.pin = GPIO_PIN5,
                  .lcd_rs.direction = OUTPUT,
                  .lcd_rs.mode = DIO,
                  .lcd_rs.pinAttach = NO_ATTACH,
                  .lcd_rs.pinOutCurrent = PIN_CURRENT_2mA,
                  .lcd_rs.state = LOW,

                  .lcd_data_pins[0].port = PORTA,
                  .lcd_data_pins[0].pin = GPIO_PIN2,
                  .lcd_data_pins[0].direction = OUTPUT,
                  .lcd_data_pins[0].mode = DIO,
                  .lcd_data_pins[0].pinAttach = NO_ATTACH,
                  .lcd_data_pins[0].pinOutCurrent = PIN_CURRENT_2mA,
                  .lcd_data_pins[0].state = LOW,

                  .lcd_data_pins[1].port = PORTA,
                  .lcd_data_pins[1].pin = GPIO_PIN3,
                  .lcd_data_pins[1].direction = OUTPUT,
                  .lcd_data_pins[1].mode = DIO,
                  .lcd_data_pins[1].pinAttach = NO_ATTACH,
                  .lcd_data_pins[1].pinOutCurrent = PIN_CURRENT_2mA,
                  .lcd_data_pins[1].state = LOW,

                  .lcd_data_pins[2].port = PORTA,
                  .lcd_data_pins[2].pin = GPIO_PIN4,
                  .lcd_data_pins[2].direction = OUTPUT,
                  .lcd_data_pins[2].mode = DIO,
                  .lcd_data_pins[2].pinAttach = NO_ATTACH,
                  .lcd_data_pins[2].pinOutCurrent = PIN_CURRENT_2mA,
                  .lcd_data_pins[2].state = LOW,

                  .lcd_data_pins[3].port = PORTA,
                  .lcd_data_pins[3].pin = GPIO_PIN5,
                  .lcd_data_pins[3].direction = OUTPUT,
                  .lcd_data_pins[3].mode = DIO,
                  .lcd_data_pins[3].pinAttach = NO_ATTACH,
                  .lcd_data_pins[3].pinOutCurrent = PIN_CURRENT_2mA,
                  .lcd_data_pins[3].state = LOW,


                  .lcd_data_pins[4].port = PORTA,
                  .lcd_data_pins[4].pin = GPIO_PIN6,
                  .lcd_data_pins[4].direction = OUTPUT,
                  .lcd_data_pins[4].mode = DIO,
                  .lcd_data_pins[4].pinAttach = NO_ATTACH,
                  .lcd_data_pins[4].pinOutCurrent = PIN_CURRENT_2mA,
                  .lcd_data_pins[4].state = LOW,


                  .lcd_data_pins[5].port = PORTA,
                  .lcd_data_pins[5].pin = GPIO_PIN7,
                  .lcd_data_pins[5].direction = OUTPUT,
                  .lcd_data_pins[5].mode = DIO,
                  .lcd_data_pins[5].pinAttach = NO_ATTACH,
                  .lcd_data_pins[5].pinOutCurrent = PIN_CURRENT_2mA,
                  .lcd_data_pins[5].state = LOW,


                  .lcd_data_pins[6].port = PORTE,
                  .lcd_data_pins[6].pin = GPIO_PIN4,
                  .lcd_data_pins[6].direction = OUTPUT,
                  .lcd_data_pins[6].mode = DIO,
                  .lcd_data_pins[6].pinAttach = NO_ATTACH,
                  .lcd_data_pins[6].pinOutCurrent = PIN_CURRENT_2mA,
                  .lcd_data_pins[6].state = LOW,


                  .lcd_data_pins[7].port = PORTE,
                  .lcd_data_pins[7].pin = GPIO_PIN5,
                  .lcd_data_pins[7].direction = OUTPUT,
                  .lcd_data_pins[7].mode = DIO,
                  .lcd_data_pins[7].pinAttach = NO_ATTACH,
                  .lcd_data_pins[7].pinOutCurrent = PIN_CURRENT_2mA,
                  .lcd_data_pins[7].state = LOW
    };

    keypad_t keypad1 = {
                        .keypad_rows[0].port = PORTB,
                        .keypad_rows[0].pin = GPIO_PIN4,
                        .keypad_rows[0].direction = OUTPUT,
                        .keypad_rows[0].mode = DIO,
                        .keypad_rows[0].pinAttach = NO_ATTACH,
                        .keypad_rows[0].pinOutCurrent = PIN_CURRENT_2mA,
                        .keypad_rows[0].state = LOW,

                        .keypad_rows[1].port = PORTB,
                        .keypad_rows[1].pin = GPIO_PIN5,
                        .keypad_rows[1].direction = OUTPUT,
                        .keypad_rows[1].mode = DIO,
                        .keypad_rows[1].pinAttach = NO_ATTACH,
                        .keypad_rows[1].pinOutCurrent = PIN_CURRENT_2mA,
                        .keypad_rows[1].state = LOW,

                        .keypad_rows[2].port = PORTB,
                        .keypad_rows[2].pin = GPIO_PIN6,
                        .keypad_rows[2].direction = OUTPUT,
                        .keypad_rows[2].mode = DIO,
                        .keypad_rows[2].pinAttach = NO_ATTACH,
                        .keypad_rows[2].pinOutCurrent = PIN_CURRENT_2mA,
                        .keypad_rows[2].state = LOW,

                        .keypad_rows[3].port = PORTB,
                        .keypad_rows[3].pin = GPIO_PIN7,
                        .keypad_rows[3].direction = OUTPUT,
                        .keypad_rows[3].mode = DIO,
                        .keypad_rows[3].pinAttach = NO_ATTACH,
                        .keypad_rows[3].pinOutCurrent = PIN_CURRENT_2mA,
                        .keypad_rows[3].state = LOW,

                        .keypad_cols[0].port = PORTB,
                        .keypad_cols[0].pin = GPIO_PIN0,
                        .keypad_cols[0].direction = INPUT,
                        .keypad_cols[0].mode = DIO,
                        .keypad_cols[0].pinAttach = PIN_PULLDOWN,
                        .keypad_cols[0].pinOutCurrent = PIN_CURRENT_2mA,
                        .keypad_cols[0].state = HIGH,

                        .keypad_cols[1].port = PORTB,
                        .keypad_cols[1].pin = GPIO_PIN1,
                        .keypad_cols[1].direction = INPUT,
                        .keypad_cols[1].mode = DIO,
                        .keypad_cols[1].pinAttach = PIN_PULLDOWN,
                        .keypad_cols[1].pinOutCurrent = PIN_CURRENT_2mA,
                        .keypad_cols[1].state = LOW,

                        .keypad_cols[2].port = PORTB,
                        .keypad_cols[2].pin = GPIO_PIN2,
                        .keypad_cols[2].direction = INPUT,
                        .keypad_cols[2].mode = DIO,
                        .keypad_cols[2].pinAttach = PIN_PULLDOWN,
                        .keypad_cols[2].pinOutCurrent = PIN_CURRENT_2mA,
                        .keypad_cols[2].state = LOW,

                        .keypad_cols[3].port = PORTB,
                        .keypad_cols[3].pin = GPIO_PIN3,
                        .keypad_cols[3].direction = INPUT,
                        .keypad_cols[3].mode = DIO,
                        .keypad_cols[3].pinAttach = PIN_PULLDOWN,
                        .keypad_cols[3].pinOutCurrent = PIN_CURRENT_2mA,
                        .keypad_cols[3].state = LOW
    };

    f32 L_f32Result = 0;
    uint8 R_u8Expresion [100] ;
    uint8 L_u8char = 255;
    uint8 L_u8Index = 0;

    gpioPinInit(&RS);
    lcd_init(&lcd1);
    keypad_init(&keypad1);

    lcd_send_string(&lcd1, (uint8*)"Mohamed Ramadan") ;
    lcd_send_string_pos(&lcd1, (uint8*)"Mohamed Abosreea" , ROW1,COL0) ;
    __delay_ms(1500) ;
    lcd_send_command(&lcd1, _LCD_CLEAR);
    __delay_ms(50);

    while(1)
    {
        keypad_get_value(&keypad1, &L_u8char) ;
        if (255 != L_u8char)
        {
            lcd_send_chr(&lcd1, L_u8char);
            R_u8Expresion [L_u8Index ++] = L_u8char ;
            if (L_u8char == '=')
            {
                R_u8Expresion [L_u8Index] = '\0' ;
                L_u8Index = 0 ;
                lcd_set_cursor(&lcd1, ROW1, COL0);
                L_f32Result = evaluateInfixExpression(R_u8Expresion) ;
                if (flag == 0)
                {
                    if (L_f32Result < 0.0 )
                    {
                        lcd_send_chr(&lcd1, '-');
                        lcd_send_floatNumber(&lcd1, (L_f32Result*-1.0)) ;
                    }
                    else
                    {
                        lcd_send_floatNumber(&lcd1, (L_f32Result*-1.0)) ;
                    }
                }
                else if (flag == 1)
                {
                    lcd_send_string(&lcd1, (uint8*)"math error");
                    flag = 0;
                }
                else if (flag == 2)
                {
                    lcd_send_string(&lcd1, (uint8*)"can't div by 0") ;
                    flag = 0;
                }
                lcd_set_cursor(&lcd1, ROW0, COL0);
            }
            if (L_u8char == 'D')
            {
                lcd_send_command(&lcd1, _LCD_CLEAR);
                __delay_ms(20);
            }
        }
    }
}

void __delay_ms(int n)
{
    volatile int i, j;
    for(i = 0 ; i < n; i++)
        for(j = 0; j < 3500; j++)
        {} /* do nothing for 1 ms */
}

void __delay_us(int n)
{
    volatile int i, j;
    for(i = 0 ; i < n; i++)
        for(j = 0; j <5 ; j++)
        {} /* do nothing for 1 us */
}
