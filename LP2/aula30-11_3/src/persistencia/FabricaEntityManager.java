/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package persistencia;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;

/**
 *
 * @author aluno
 */
public class FabricaEntityManager {
    
    private static EntityManagerFactory entityManagerFactory = null;
    
    private FabricaEntityManager(){}
    
    static{
        entityManagerFactory = Persistence.createEntityManagerFactory("aula30-11PU");
    }
    
    public static EntityManager getEntityManager() throws PersistenciaException{
        if(entityManagerFactory == null){
            throw new PersistenciaException("Unidade de persistencia nao iniciada");
        }
        return entityManagerFactory.createEntityManager();
        
    }
}