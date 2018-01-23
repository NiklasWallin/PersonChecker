import QtQuick 2.6
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import io.qt.examples.person 1.0

ApplicationWindow {
    id: root
    width: 600
    height: 800
    visible: true
    color: "lightgreen"
    Person { id: person }
    ListView{
        implicitHeight: parent.height
        implicitWidth: parent.width
        Text{
            anchors.bottom: signumfield.top
            anchors.bottomMargin: 10
            anchors.left: signumfield.left
            anchors.right: signumfield.right

            text:"Enter a person signum below"
            Layout.fillWidth: true
        }
        TextField {
            id:signumfield
            anchors.centerIn: parent
            text: person.Signum = text
            placeholderText: qsTr("Enter a finnish person signum")
            onTextChanged: person.Signum = text
        }
        Button{
            id:checkButton
            anchors.top: signumfield.bottom
            anchors.topMargin: 10
            anchors.left: signumfield.left
            anchors.right: signumfield.right
            text: "Check signum"
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    if(signumfield.text.length == 11){

                        person.calcAge(signumfield.text);
                        person.checkIfValid(signumfield.text);
                        person.getGender(signumfield.text);

                        if(person.Age >= 0 && person.IsValidSignum != "invalid")
                            resultText.text = ("Is the signum valid: " + person.IsValidSignum +
                                               "\nThis person is a " + person.Gender + " who is " + person.Age + " years old")
                        else
                            resultText.text = "Invalid signum, please try again."
                    }
                    else
                        resultText.text = "Invalid signum, please try again."
                }
            }
        }
        Text {
            id: resultText
            anchors.top: checkButton.bottom
            anchors.topMargin: 10
            anchors.left: checkButton.left
            anchors.right: checkButton.right
            text: ""
        }
    }
}

























