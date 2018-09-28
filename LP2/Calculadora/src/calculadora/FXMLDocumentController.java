package calculadora;

import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javax.script.*;
import javax.script.ScriptEngineManager;
import javax.script.ScriptException;

/**
 *
 * @author Nicolas T
 */
public class FXMLDocumentController implements Initializable {

    @FXML
    private Label CampoResultado;
    @FXML
    private Button B1;

    @FXML
    private Button B2;
    @FXML
    private Button B3;
    @FXML
    private Button B4;
    @FXML
    private Button B5;
    @FXML
    private Button B6;
    @FXML
    private Button B7;
    @FXML
    private Button B8;
    @FXML
    private Button B9;
    @FXML
    private Button B0;
    @FXML
    private Button Bdiv;
    @FXML
    private Button Bmult;
    @FXML
    private Button Bsubt;
    @FXML
    private Button Bsoma;
    @FXML
    private Button Bponto;

    @FXML
    private void B1(ActionEvent event) {
        this.CampoResultado.setText(this.CampoResultado.getText() + "1");
    }

    @FXML
    private void B2(ActionEvent event) {
        this.CampoResultado.setText(this.CampoResultado.getText() + "2");
    }

    @FXML
    private void B3(ActionEvent event) {
        this.CampoResultado.setText(this.CampoResultado.getText() + "3");
    }

    @FXML
    private void B4(ActionEvent event) {
        this.CampoResultado.setText(this.CampoResultado.getText() + "4");
    }

    @FXML
    private void B5(ActionEvent event) {
        this.CampoResultado.setText(this.CampoResultado.getText() + "5");
    }

    @FXML
    private void B6(ActionEvent event) {
        this.CampoResultado.setText(this.CampoResultado.getText() + "6");
    }

    @FXML
    private void B7(ActionEvent event) {
        this.CampoResultado.setText(this.CampoResultado.getText() + "7");
    }

    @FXML
    private void B8(ActionEvent event) {
        this.CampoResultado.setText(this.CampoResultado.getText() + "8");
    }

    @FXML
    private void B9(ActionEvent event) {
        this.CampoResultado.setText(this.CampoResultado.getText() + "9");
    }

    @FXML
    private void B0(ActionEvent event) {
        this.CampoResultado.setText(this.CampoResultado.getText() + "0");
    }

    @FXML
    private void Bsoma(ActionEvent event) {
        this.CampoResultado.setText(this.CampoResultado.getText() + "+");
    }

    @FXML
    private void Bsubt(ActionEvent event) {
        this.CampoResultado.setText(this.CampoResultado.getText() + "-");
    }

    @FXML
    private void Bmult(ActionEvent event) {
        this.CampoResultado.setText(this.CampoResultado.getText() + "*");
    }

    @FXML

    private void Bdivi(ActionEvent event) {
        this.CampoResultado.setText(this.CampoResultado.getText() + "/");
    }

    @FXML
    private void Bponto(ActionEvent event) {

        this.CampoResultado.setText(this.CampoResultado.getText() + ".");
    }

    @FXML
    private void Bigual(ActionEvent event) throws ScriptException {
        try {
            ScriptEngineManager factory = new ScriptEngineManager();
            // create a JavaScript engine
            ScriptEngine engine = factory.getEngineByName("JavaScript");
            // evaluate JavaScript code from String
            Object obj = engine.eval(this.CampoResultado.getText());
            System.out.println(obj);
            this.CampoResultado.setText(String.valueOf(obj));
        } catch (Exception ex) {
            this.CampoResultado.setText("");
        }
    }

    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
    }

}
