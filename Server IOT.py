import socket
# Configuración del servidor
host = '192.168.74.148'
port = 1000
clientes = {}
con_DHT = 0
con_LCD = 0
VALID_TOKENS = ['dht11']

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((host, port))
    s.listen(2)
    print('Servidor iniciado. Esperando conexiones...')
    data=None
    while True: 
            switch=0
            conn, addr = s.accept()
            token = conn.recv(1024).decode()
            print(token)
            if token =="dht11" and switch==0:
                clientes["cliente_1"] = conn
                data = conn.recv(1024).decode()
                print(data)
                print(f'Conectado al cliente DHT desde {addr[0]}')
                print("entra")
                switch=1
            else:
                print("data: ",data)
                print(f'Conexion desde LCD {addr[0]}')
                clientes["cliente_2"] = conn
                if data:
                    print(data+'\n')
                    conn.send(data.encode('utf-8'))
                    print(str(data).encode('utf-8'))
                print("entra2")
                switch=0
    
client1_socket.close()
client2_socket.close()
server_socket.close()
