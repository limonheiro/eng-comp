
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
@Table(name="a")
public class A_VO {
    @Id
    @GeneratedValue(strategy=GenerationType.SEQUENCE)
    private int codigo;
    
    @Column(length=40, nullable=false)
    private String nome;
    
    @ManyToMany(fetch=FetchType.LAZY)
    private Set<B_VO> listaB;

    public Set<B_VO> getListaB() {
        return listaB;
    }

    public void setListaB(Set<B_VO> listaB) {
        this.listaB = listaB;
    }
    /**
     * @return the codigo
     */
    public int getCodigo() {
        return codigo;
    }

    /**
     * @param codigo the codigo to set
     */
    public void setCodigo(int codigo) {
        this.codigo = codigo;
    }

    /**
     * @return the nome
     */
    public String getNome() {
        return nome;
    }

    /**
     * @param nome the nome to set
     */
    public void setNome(String nome) {
        this.nome = nome;
    }
    }
