/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package persistencia;

/**
 *
 * @author sky
 */
public class DAO {
    ConexaoBD conexao;
    
    public DAO(ConexaoBD conexao) throws PersistenciaException{
        this.conexao=conexao;
    }

    public ConexaoBD getConexao() {
        return conexao;
    }

    public void setConexao(ConexaoBD conexao) {
        this.conexao = conexao;
    }
    public void desconectarBD() throws PersistenciaException {
        conexao.desconectar();
    }
}
