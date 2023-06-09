using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour
{
    private Camera MainCam;
    public float DPIX = 1.0f;
    public float DPIY = 1.0f;
    public float MoveSpeed = 0.01f;
    // Start is called before the first frame update
    void Start()
    {
        MainCam = Camera.main;
        Cursor.lockState = CursorLockMode.Locked;
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Escape))
        {
            Cursor.lockState = CursorLockMode.None;
        }
        float mousex = Input.GetAxis("Mouse X");
        float mousey = Input.GetAxis("Mouse Y");
        transform.Rotate(0f, mousex * DPIX, 0f);
        MainCam.transform.Rotate(mousey * DPIY, 0f, 0f);

        //横矢印入力を値で返し変数「Horizontal」に格納
        float Horizontal = Input.GetAxis("Horizontal");
        //縦矢印入力を値で返し変数「Vertical」に格納
        float Vertical = Input.GetAxis("Vertical");
        //このまま入れると早すぎる為MoveSpeedで調整
        transform.position += transform.right * Horizontal * MoveSpeed;
        transform.position += transform.forward * Vertical * MoveSpeed;
    }
}
