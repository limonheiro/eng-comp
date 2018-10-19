/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package execucao;

import java.util.List;
import javax.swing.JOptionPane;
import negocio.AlunoNegocio;
import negocio.NegocioException;
import vo.AlunoVO;
import vo.EnumSexo;
import vo.EnumUF;

/**
 *
 * @author sky
 */
public class Principal {

    private static AlunoNegocio alunoNegocio;

    public static void main(String[] args) {
        try {
            alunoNegocio = new AlunoNegocio();
        } catch (NegocioException ex) {
            System.out.println("Camada de negocio e persistencia nao iniciada - " + ex.getMessage());
        }
        if (alunoNegocio != null) {
            EnumMenuAluno opcao = EnumMenuAluno.Sair;
            do {
                try {
                    opcao = exibirMenu();
                    switch (opcao) {
                        case IncluirAluno:
                            incluirAluno();
                            break;
                        case AlterarAluno:
                            alterarAluno();
                            break;
                        case ExcluirAluno:
                            excluirAluno();
                            break;
                        case PesqMatricula:
                            pesquisarPorMatricula();
                            break;
                        case PesqNome:
                            pesquisarPorNome();
                    }
                } catch (NegocioException ex) {
                    System.out.println("Operação não realizada corretamente" + ex.getMessage());
                }
            } while (opcao != EnumMenuAluno.Sair);
        }
        System.exit(0);
    }

    private static void incluirAluno() throws NegocioException {
        AlunoVO alunoTemp = lerDados();
        alunoNegocio.inserir(alunoTemp);
    }

    private static void alterarAluno() throws NegocioException {
        int matricula = 0;
        try {
            matricula = Integer.parseInt(JOptionPane.showInputDialog(null, "Forneca a matricula do Aluno", JOptionPane.QUESTION_MESSAGE));
        } catch (Exception ex) {
            JOptionPane.showMessageDialog(null, "Digitação inconsistente - " + ex.getMessage());
        }
        AlunoVO alunoVO = alunoNegocio.pesquisaMatricula(matricula);
        if (alunoVO != null) {
            AlunoVO alunoTemp = lerDados(alunoVO);
            alunoNegocio.alterar(alunoTemp);
        } else {
            JOptionPane.showMessageDialog(null, "Aluno não localizado");
        }
    }

    private static void excluirAluno() throws NegocioException {
        int matricula = 0;
        try {
            matricula = Integer.parseInt(JOptionPane.showInputDialog(null, "Forneça a matricula do Aluno", "Leitura de Dados", JOptionPane.QUESTION_MESSAGE));
        } catch (Exception ex) {
            JOptionPane.showMessageDialog(null, "Digitação inconsistente - " + ex.getMessage());
        }
        AlunoVO alunoVO = alunoNegocio.pesquisaMatricula(matricula);
        if (alunoVO != null) {
            alunoNegocio.excluir(alunoVO.getMatricula());
        } else {
            JOptionPane.showMessageDialog(null, "Aluno não localizado");
        }
    }

    private static void pesquisarPorMatricula() throws NegocioException {
        int matricula = 0;
        try {
            matricula = Integer.parseInt(JOptionPane.showInputDialog(null, "Forneção a matricula do Aluno", "Leitura de Dados", JOptionPane.QUESTION_MESSAGE));
        } catch (Exception ex) {
            JOptionPane.showMessageDialog(null, "Digitação inconsistente - " + ex.getMessage());
        }
        AlunoVO alunoVO = alunoNegocio.pesquisaMatricula(matricula);
        if (alunoVO != null) {
            mostrarDados(alunoVO);
        } else {
            JOptionPane.showMessageDialog(null, "Aluno não encontrado");
        }
    }

    private static void pesquisarPorNome() throws NegocioException {
        String nome = JOptionPane.showInputDialog(null, "Forneça o nome do Aluno", "Leitura de Dados", JOptionPane.QUESTION_MESSAGE);
        if (nome != null) {
            List<AlunoVO> listaAlunoVO = alunoNegocio.pesquisaParteNome(nome);

            if (listaAlunoVO.size() > 0) {
                for (AlunoVO alunoVO : listaAlunoVO) {
                    mostrarDados(alunoVO);
                }
            } else {
                JOptionPane.showMessageDialog(null, "Aluno não localizado");
            }
        } else {
            JOptionPane.showMessageDialog(null, "Nome não pode ser nulo");
        }
    }

    private static void mostrarDados(AlunoVO alunoVO) {
        if (alunoVO != null) {
            System.out.println("Matricula: " + alunoVO.getMatricula());
            System.out.println("Nome: " + alunoVO.getNome());
            System.out.println("Nome da Mãe: " + alunoVO.getNomeMae());
            System.out.println("Nome do Pai: " + alunoVO.getNomePai());
            System.out.println("Sexo: " + alunoVO.getSexo().name());
            if (alunoVO.getEndereco() != null) {
                System.out.println("Logradouro: " + alunoVO.getEndereco().getLogradouro());
                System.out.println("Numero: " + alunoVO.getEndereco().getNumero());
                System.out.println("Bairro: " + alunoVO.getEndereco().getBairro());
                System.out.println("Cidade: " + alunoVO.getEndereco().getCidade());
                System.out.println("UF: " + alunoVO.getEndereco().getUf());
                System.out.println("---------------------------------------------");
            }
        }
    }

    private static AlunoVO lerDados(AlunoVO alunoTemp) {
        String nome, nomeMae, nomePai, logradouro, bairro, cidade;
        int numero;
        EnumSexo sexo;
        EnumUF uf;
        try {
            nome = JOptionPane.showInputDialog("Forneça o nome do Aluno", alunoTemp.getNome().trim());
            alunoTemp.setNome(nome);
            nomeMae = JOptionPane.showInputDialog("Forneça o nome da mãe do ALuno", alunoTemp.getNomeMae().trim());
            nomePai = JOptionPane.showInputDialog("Forneça o nome do pai do Aluno", alunoTemp.getNomePai().trim());
            sexo = (EnumSexo) JOptionPane.showInputDialog(null, "Escolha uma opção", "Leitura de dados", JOptionPane.QUESTION_MESSAGE, null, EnumSexo.values(), alunoTemp.getSexo());
            logradouro = JOptionPane.showInputDialog("Forneça o logradouro do endereco", alunoTemp.getEndereco().getLogradouro().trim());
            numero = Integer.parseInt(JOptionPane.showInputDialog("Forneça o numero no endereco", alunoTemp.getEndereco().getNumero()));
            bairro = JOptionPane.showInputDialog("Forneça o bairro no endereço ", alunoTemp.getEndereco().getBairro().trim());
            cidade = JOptionPane.showInputDialog("Forneça a cidade do endereço", alunoTemp.getEndereco().getCidade().trim());
            uf = (EnumUF) JOptionPane.showInputDialog(null, "escolha uma Opção", "Leitura de Dados", JOptionPane.QUESTION_MESSAGE,null, EnumUF.values(), alunoTemp.getEndereco().getUf());
            
            alunoTemp.getEndereco().setUf(uf);
        }catch(Exception ex){
            System.out.println("Digitação inconsistente - "+ex.getMessage());
        }
        return alunoTemp;
    }
    private static AlunoVO lerDados(){
        AlunoVO alunoTemp = new AlunoVO();
        return lerDados(alunoTemp);
    }
    
    private static EnumMenuAluno exibirMenu(){
        EnumMenuAluno opcao;
        opcao = (EnumMenuAluno) JOptionPane.showInputDialog(null, "Escolha uma Opção", "Menu", JOptionPane.QUESTION_MESSAGE, null, EnumMenuAluno.values(), EnumMenuAluno.values()[0]);
        if(opcao == null){
            JOptionPane.showMessageDialog(null, "Nenhuma Opção Escolhida");
            opcao = EnumMenuAluno.Sair;
        }
        return opcao;
    }
}
