from taipy import Gui

value = ""
value2 = ""
value3 = ""
index="""

<|text-center|
# Torture Clock Alarm

Welcome to our torture clock!

Input Hours: <|{value}|number|>

Input Minutes: <|{value2}|number|>
<|text-center|
Choose a Torture Method: 
<|{value3}|selector|lov=Annoying Buzzer;Boxing Glove Smack;Waterjet|dropdown|>
<|Confirm|button|>

>
"""
ourApp = Gui(page=index)


if __name__ == "__main__":
    ourApp.run(use_reloader=True)