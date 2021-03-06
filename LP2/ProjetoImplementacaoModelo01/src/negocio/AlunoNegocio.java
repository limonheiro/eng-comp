/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package negocio;

import java.util.List;
import persistencia.AlunoDAO;
import persistencia.ConexaoBD;
import persistencia.PersistenciaException;
import vo.AlunoVO;

public class AlunoNegocio {

    private AlunoDAO alunoDAO;

    public AlunoNegocio() throws NegocioException {
        try {
            this.alunoDAO = new AlunoDAO(ConexaoBD.getInstancia());
        } catch (PersistenciaException ex) {
            throw new NegocioException("Erro ao iniciar a Persistencia - " + ex.getMessage());
        }
    }

    public void inserir(AlunoVO alunoVO) throws NegocioException {
        String mensagemErros = this.validarDados(alunoVO);

        if (!mensagemErros.isEmpty()) {
            throw new NegocioException(mensagemErros);
        }

        try {
            if (alunoDAO.incluir(alunoVO) == 0) {
                throw new NegocioException("Inclusão não realizada!!");
            }
        } catch (PersistenciaException ex) {
            throw new NegocioException("Erro ao incluir o produto - " + ex.getMessage());
        }
    }

    public void alterar(AlunoVO alunoVO) throws NegocioException {
        String mensagemErros = this.validarDados(alunoVO);

        if (!mensagemErros.isEmpty()) {
            throw new NegocioException(mensagemErros);
        }

        try {
            if (alunoDAO.alterar(alunoVO) == 0) {
                throw new NegocioException("Alteração não realizada!!");
            }
        } catch (PersistenciaException ex) {
            throw new NegocioException("Erro ao alterar o produto - " + ex.getMessage());
        }
    }

    public void excluir(int codigo) throws NegocioException {
        try {
            if (alunoDAO.excluir(codigo) == 0) {
                throw new NegocioException("Alteração não realizada!!");
            }
        } catch (PersistenciaException ex) {
            throw new NegocioException("Erro ao excluir o aluno - " + ex.getMessage());
        }
    }

    public List<AlunoVO> pesquisaParteNome(String parteNome) throws NegocioException {
        try {
            return alunoDAO.buscarPorNome(parteNome);
        } catch (PersistenciaException ex) {
            throw new NegocioException("Erro ao pesquisar aluno pela matricula - " + ex.getMessage());
        }
    }

    public AlunoVO pesquisaMatricula(int matricula) throws NegocioException {
        try {
            return alunoDAO.buscarPorMatricula(matricula);
        } catch (PersistenciaException ex) {
            throw new NegocioException("Erro ao pesquisa aluno pela matricula - " + ex.getMessage());
        }
    }

    private String validarDados(AlunoVO alunoVO) {
        String mensagemErros = "";
        if (alunoVO.getNome() == null || alunoVO.getNome().length() == 0) {
            mensagemErros += "\nNome do aluno não pode ser vazio";
        }
        if (alunoVO.getNomeMae() == null || alunoVO.getNomeMae().length() == 0) {
            mensagemErros += "\nNome da mae não poder ser vazio";
        }
        if (alunoVO.getNomePai() == null || alunoVO.getNomePai().length() == 0) {
            mensagemErros += "\nNome da pai não poder ser vazio";
        }
        if (alunoVO.getSexo() == null) {
            mensagemErros += "\nSexo não pode ser nulo";
        }
        if (alunoVO.getEndereco().getLogradouro() == null || alunoVO.getEndereco().getLogradouro().length() == 0) {
            mensagemErros += "\nLogradouro não deve ser vazio";
        }
        if (alunoVO.getEndereco().getNumero() <= 0) {
            mensagemErros += "\nNumero deve ser maior que zero";
        }
        if (alunoVO.getEndereco().getBairro() == null || alunoVO.getEndereco().getBairro().length() == 0) {
            mensagemErros += "\nBairro não deve ser vazio";
        }
        if (alunoVO.getEndereco().getCidade() == null || alunoVO.getEndereco().getCidade().length() == 0) {
            mensagemErros += "\nCidade não deve ser vazio";
        }
        if (alunoVO.getEndereco().getUf() == null) {
            mensagemErros += "\nUF não pode ser vazio";
        }
        return mensagemErros;
    }
}
