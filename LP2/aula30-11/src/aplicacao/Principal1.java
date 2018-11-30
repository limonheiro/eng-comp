/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aplicacao;

import javax.persistence.EntityManager;
import persistencia.FabricaEntityManager;
import persistencia.PersistenciaException;
import vo.A_VO;

public class Principal1 {
    public static void main(String[] args) {
        try {
            EntityManager entityManager = FabricaEntityManager.getEntityManager();
            A_VO a =new A_VO();
            a.setNome("a");
            
            entityManager.getTransaction().begin();
            entityManager.persist(a);
            entityManager.getTransaction().commit();
        } catch (PersistenciaException ex) {
            System.out.println(ex.toString());
        }
   
    }
}
