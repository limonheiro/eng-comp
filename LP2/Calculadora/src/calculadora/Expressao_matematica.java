/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package calculadora;

import javax.script.*;

/**
 *
 * @author Nicolas T
 */
public class Expressao_matematica {
    public static void main( String[] args ) throws Exception {
// create a script engine manager
        ScriptEngineManager factory = new ScriptEngineManager();
        // create a JavaScript engine
        ScriptEngine engine = factory.getEngineByName("JavaScript");
        // evaluate JavaScript code from String
        Object obj = engine.eval("1 + 1*2-2");
        System.out.println (obj); // imprime "1.0"
        //System.out.println (obj.getClass()); // imprime "java.lang.Double" 
   }
}
