/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aplicacao;

import javax.persistence.EntityManager;
import javax.persistence.Query;
import persistencia.FabricaEntityManager;
import vo.B_VO;

public class Principal3 {
    public static void main(String[] args) {
        try {
            EntityManager entityManager = FabricaEntityManager.getEntityManager();
            entityManager.getTransaction().begin();
            Query query = entityManager.createQuery("SELECT b FROM B_VO b WHERE b.nome = 'b'");
            B_VO b =(B_VO)query.getSingleResult();
            
            if(b != null){
                System.out.println("Codigo B:" + b.getCodigo());
            }
        } catch (Exception e) {
        }
    }
}
