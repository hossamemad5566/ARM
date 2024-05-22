Project Overview:

This project demonstrates a multi-tasking application using FreeRTOS on an embedded system. It implements three FreeRTOS tasks:

vTask_Input: Continuously reads user input from a UART channel. It resets the system if no input is received for 5 seconds after starting password entry.
vTask_Display: Handles user interface and state management on an LCD display. It displays prompts and feedback based on user actions.
vTask_Password_Check: Compares user input password with a stored password and signals access granted/denied. It blocks further password attempts after 4 consecutive incorrect entries.
Communication between tasks is achieved using FreeRTOS queues (Display_Queue) and semaphores (CheckPasswordSemaphore).

Code Modifications (Potential):

1. vTask_Display Function:

Introduce a timer variable to track the time since the last user input.
In the while(1) loop:
Update the timer variable on each loop iteration.
If LCD_CurrentState is Recieving and the timer exceeds 5 seconds (adjust as needed), reset the system by:
Setting LCD_CurrentState to Welcome.
Clearing the password buffer (g_Password).
Sending a message to the UART indicating a timeout and system reset.
2. vTask_Password_Check Function:

Introduce a counter variable to track the number of consecutive incorrect password attempts.
After an unsuccessful password check:
Increment the counter variable.
If the counter reaches 4, block further password attempts by:
Disabling vTask_Input (potential implementation depends on your system).
Sending a message to the UART indicating password attempts are blocked.
Consider implementing a mechanism to unblock password attempts after a certain time or user action (optional).    
