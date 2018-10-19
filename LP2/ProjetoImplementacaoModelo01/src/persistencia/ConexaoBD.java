/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package persistencia;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

/**
 *
 * @author sky
 */
public class ConexaoBD {
    private Connection con;
    private static ConexaoBD instancia;
    
    private ConexaoBD() throws PersistenciaException{
        try{
            Class.forName("org.postgresql.Driver");
            String url = "jdbc:postgresql://localhost:5432/academico";
            con = DriverManager.getConnection(url, "postgres", "postgres");
        }catch(SQLException ex){
            throw new PersistenciaException("Erro ao conectar o banco de dados - "+ex.toString());
        }catch(ClassNotFoundException ex){
            throw new PersistenciaException("Driver do banco de dados não loclaizado - "+ex.toString());
        }
    }
    public static ConexaoBD getInstancia() throws PersistenciaException{
        if(instancia == null){
            instancia = new ConexaoBD();
        }
        return instancia;
    }
    public Connection getConexao(){
        return con;
    }
    public void desconectar() throws PersistenciaException{
        try{
            con.close();
        }catch (SQLException ex){
            throw new PersistenciaException("Erro ao desconectar o banco de dados - "+ex.toString());
        }
    }
}
