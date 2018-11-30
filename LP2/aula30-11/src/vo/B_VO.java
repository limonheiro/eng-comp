/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package vo;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.FetchType;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.OneToOne;
import javax.persistence.Table;

@Entity
@Table(name="b")
public class B_VO {
    @Id
    @GeneratedValue(strategy=GenerationType.SEQUENCE)
    private int codigo;

    public int getCodigo() {
        return codigo;
    }

    public void setCodigo(int codigo) {
        this.codigo = codigo;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public A_VO getA_VO() {
        return a_VO;
    }

    public void setA_VO(A_VO a_VO) {
        this.a_VO = a_VO;
    }
    
    @Column(length=40, nullable=false)
    private String nome;
    
    @OneToOne(fetch=FetchType.EAGER)
    private A_VO a_VO;
}   
    
