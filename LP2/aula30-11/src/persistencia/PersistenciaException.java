/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package persistencia;

public class PersistenciaException extends Exception{

    public PersistenciaException() {
        super("Erro de persistencia");
    }

    public PersistenciaException(String msg) {
        super(msg);
    }

}
