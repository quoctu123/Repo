import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Máy Tính")

    Column {
        anchors.centerIn: parent
        spacing: 10

        TextField {
            id: input1
            width: 200
            placeholderText: "Nhập số thứ nhất"
        }

        TextField {
            id: input2
            width: 200
            placeholderText: "Nhập số thứ hai"
        }

        Row {
            spacing: 10

            Button {
                text: "+"
                onClicked: calculate("+")
            }
            Button {
                text: "-"
                onClicked: calculate("-")
            }
            Button {
                text: "*"
                onClicked: calculate("*")
            }
            Button {
                text: "/"
                onClicked: calculate("/")
            }
        }

        Label {
            id: result
            text: "Kết quả: "
            font.pixelSize: 16
        }
    }

    function calculate(op) {
        var num1 = input1.text.trim();
        var num2 = input2.text.trim();
        var res;

        if (op === "+") res = calculator.add(num1, num2);
        else if (op === "-") res = calculator.subtract(num1, num2);
        else if (op === "*") res = calculator.multiply(num1, num2);
        else if (op === "/") res = calculator.divide(num1, num2);

        // Kiểm tra nếu res là NaN
        if (res === "Lỗi nhập" || res === "" || res === "NaN") {
            result.text = "Lỗi nhập: Vui lòng nhập số hợp lệ";
        } else {
            result.text = "Kết quả: " + res;
        }
    }
}
