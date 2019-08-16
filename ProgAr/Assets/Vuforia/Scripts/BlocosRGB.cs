using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.UI;

public class BlocosRGB : MonoBehaviour
{
	string ipv4 = "http://192.168.0.118";
	string setURL;
	public GameObject target;

    // Start is called before the first frame update
    void Start()
    {

		setURL = ipv4 +"/Wdata.php?dados=";
    }

    // Update is called once per frame
    void Update()
    {
		target = GameObject.Find ("azul");
		StartCoroutine (GetText ());   

    }
	public IEnumerator GetText(){


		UnityWebRequest www = UnityWebRequest.Get(ipv4 + "/Rdata.php");
		//UnityWebRequest www = UnityWebRequest.Get("setURL");
		yield return www.SendWebRequest();

		if (www.isNetworkError || www.isHttpError) {
			Debug.Log (www.error);
		} 
		else {
			byte[] results = www.downloadHandler.data;
			string dados = System.Text.Encoding.Default.GetString (results).ToString ();

			/*if (dados.Contains ("verde")) {
				StartCoroutine (SetText ("Verde"));
				StopCoroutine ("GetText");

			} else if (dados.Contains ("azul")) {
				StartCoroutine (SetText ("Azul"));
				StopCoroutine ("GetText");

			} else {
			}*/


			StopCoroutine (GetText());
		}
	}
	public IEnumerator SetText(string data){
		string URL = setURL + data;
		WWW www = new WWW (URL);
		yield return www;

		StopCoroutine ("SetText");

	}
	public void verde(){
		StartCoroutine (SetText ("verde"));
	}

}
