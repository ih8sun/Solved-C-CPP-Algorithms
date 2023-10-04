void ingresarHerramienta(struct herramienta tools[],int i){

    cout<<"\n\n\t\t[ INGRESO DE HERRAMIENTA N. -> "<<i<<" ]\n\n";

    cout<<"Ingresa registro de  herramienta: ";
    cin>>tools[i].registro;
    
    cout<<"Ingresa el nombre: ";
    fflush(stdin);
    gets(tools[i].nombre);
    
    cout<<"Ingresa la cantidad: ";
    cin>>tools[i].cantidad;

    cout<<"Ingresa el valor: ";
    cin>>tools[i].valor;


}