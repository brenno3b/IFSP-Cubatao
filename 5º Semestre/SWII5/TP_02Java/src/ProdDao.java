/*
 * Brenno Barbosa Bezerra - CB3007219
 * Diego Pereira Gonzalez Natalo - CB3005585
 */

import java.util.*;
import java.sql.*;

public class ProdDao {
	public static Connection getConnection(){
		
		Connection con=null;
		try{
			String dbDriver = "com.mysql.cj.jdbc.Driver";
			String dbURL = "jdbc:mysql://localhost:3306/";
			String dbName = "db_tp02";
			String dbUsername = "root";
			String dbPassword = "teste123456";

			Class.forName(dbDriver);
			con = DriverManager.getConnection(dbURL + dbName, dbUsername, dbPassword); 
		}
		catch(Exception e){
			System.out.println(e);
		}
		return con;
	}
	
	public static int save(Prod e){
		int status=0;
		try{
			Connection con=ProdDao.getConnection();
			PreparedStatement ps=con.prepareStatement("insert into produtos(nome, unidadeCompra, descricao, qtdPrevistoMes, precoMaxComprado) values (?,?,?,?,?)");
			ps.setString(1,e.getNome());
			ps.setString(3,e.getDescricao());
			ps.setInt(2,e.getUnidadeCompra());
			ps.setFloat(4,e.getQtdPrevistoMes());
			ps.setFloat(5,e.getPrecoMaxComprado());
			
			status=ps.executeUpdate();
			
			con.close();
		}
		catch(Exception ex){
			ex.printStackTrace();
		}

		return status;
	}
	
	public static int update(Prod e){
		int status=0;
		try{
			Connection con=ProdDao.getConnection();
			PreparedStatement ps=con.prepareStatement("update produtos set nome=?,unidadeCompra=?,descricao=?,qtdPrevistoMes=?, precoMaxComprado=? where id=?");
			ps.setString(1,e.getNome());
			ps.setString(3,e.getDescricao());
			ps.setInt(2,e.getUnidadeCompra());
			ps.setFloat(4,e.getQtdPrevistoMes());
			ps.setFloat(5,e.getPrecoMaxComprado());
			ps.setInt(6,e.getId());

			status=ps.executeUpdate();

			con.close();
		}
		catch(Exception ex){
			ex.printStackTrace();
		}

		return status;
	}
	
	public static int delete(int id){
		int status=0;
		try{
			Connection con=ProdDao.getConnection();
			PreparedStatement ps=con.prepareStatement("delete from produtos where id=?");
			ps.setInt(1,id);
			status=ps.executeUpdate();

			con.close();
		}
		catch(Exception e){
			e.printStackTrace();
		}

		return status;
	}
	
	public static Prod getProductsById(int id){
		Prod e=new Prod();

		try{
			Connection con=ProdDao.getConnection();
			PreparedStatement ps=con.prepareStatement("select * from produtos where id=?");
			ps.setInt(1,id);
			ResultSet rs=ps.executeQuery();
			if(rs.next()){
				e.setId(rs.getInt(1));
				e.setNome(rs.getString(2));
				e.setDescricao(rs.getString(4));
				e.setUnidadeCompra(rs.getInt(3));
				e.setPrecoMaxComprado(rs.getFloat(5));
				e.setQtdPrevistoMes(rs.getFloat(6));
			}
		con.close();
		}catch(Exception ex){
			ex.printStackTrace();
		}

		return e;
	}
	public static List<Prod> getAllProducts(){
		List<Prod> list=new ArrayList<Prod>();
		
		try{
			Connection con=ProdDao.getConnection();
			PreparedStatement ps=con.prepareStatement("select * from produtos");
			ResultSet rs=ps.executeQuery();
			while(rs.next()){
				Prod e=new Prod();
				e.setId(rs.getInt(1));
				e.setNome(rs.getString(2));
				e.setDescricao(rs.getString(4));
				e.setUnidadeCompra(rs.getInt(3));
				e.setPrecoMaxComprado(rs.getFloat(5));
				e.setQtdPrevistoMes(rs.getFloat(6));
				list.add(e);
			}
			con.close();
		}catch(Exception e){
			e.printStackTrace();
		}

		return list;
	}

}
