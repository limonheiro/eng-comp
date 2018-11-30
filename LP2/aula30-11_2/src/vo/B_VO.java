/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package vo;
import java.util.Set;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.FetchType;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.ManyToMany;
import javax.persistence.Table;

@Entity
@Table(name="b")
public class B_VO {
    @Id
    @GeneratedValue(strategy=GenerationType.SEQUENCE)
    private int codigo;
    
    @Column(length=40, nullable=false)
    private String nome;

    @ManyToMany(mappedBy="listaB",fetch=FetchType.LAZY)
    private Set<A_VO> listaA;

    public Set<A_VO> getListaA() {
        return listaA;
    }

    public void setListaA(Set<A_VO> listaA) {
        this.listaA = listaA;
    }


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

}   
    
