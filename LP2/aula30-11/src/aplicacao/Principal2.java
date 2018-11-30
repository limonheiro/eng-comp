/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aplicacao;

import javax.persistence.EntityManager;
import javax.persistence.Query;
import persistencia.FabricaEntityManager;
import persistencia.PersistenciaException;
import vo.A_VO;
import vo.B_VO;

public class Principal2 {
    public static void main(String[] args) {
        try {
            EntityManager entityManager = FabricaEntityManager.getEntityManager();
            entityManager.getTransaction().begin();
            Query query = entityManager.createQuery("SELECT a FROM A_VO a WHERE a.nome ='a'");
            A_VO a = (A_VO)query.getSingleResult();
            a.setNome("a1");
            
            B_VO b =new B_VO();
            b.setNome("b");
            b.setA_VO(a);
            
            entityManager.persist(b);
            entityManager.getTransaction().commit();
        } catch (PersistenciaException ex) {
            System.out.println(ex.toString());
        }
    }
}
