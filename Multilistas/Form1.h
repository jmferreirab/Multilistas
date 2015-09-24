#pragma once

namespace Multilistas {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{

		ref struct Barco
		{
			String^ Nombre;		
			Barco^ Siguiente;
		};
		ref struct Estacion
		{
			String^ Nombre;
			Estacion^ SgtEst;
			Barco^ Cola;
		};
		static Estacion ^PTREstacion=nullptr;
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::ListBox^  listBox2;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;

	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>

		void CrearEstacion(String^ NombreEst)
		{
			Estacion^ Q= gcnew Estacion();
			Q->Nombre =NombreEst;
			if(PTREstacion==nullptr)
			{
				PTREstacion=Q;
			}
			else
			{
				Estacion^ P= PTREstacion;
				while(P->SgtEst!=nullptr)
				{
					P=P->SgtEst;
				}
				P->SgtEst=Q;
			}
		}

		void MostrarEstaciones()
		{
			listBox1->Items->Clear();
			Estacion^ P= PTREstacion;
			while(P!=nullptr)
			{
				listBox1->Items->Add(P->Nombre);
				P=P->SgtEst;
			}
		}

		void AgregarBarco(int indice,String^ ShipName)
		{
			Barco^ Boat = gcnew Barco();
			Boat->Nombre = ShipName;
			int i=0;
			Estacion^ P =PTREstacion;
			while(i!=indice)
			{
				P=P->SgtEst;
				i++;
			}
			if(P->Cola==nullptr)
			{
				P->Cola = Boat;
			}
			else
			{
				Barco^ S = P->Cola;
				while(S->Siguiente!=nullptr)
				{
					S=S->Siguiente;
				}
				S->Siguiente=Boat;
			}
		}

		void MostrarFlota(int index)
		{
			int i=0;
			Estacion^ P=PTREstacion;
			while(i!=index)
			{
				P=P->SgtEst;
				i++;
			}
			listBox2->Items->Clear();
			Barco^ S= P->Cola;
			while(S!=nullptr)
			{
				listBox2->Items->Add(S->Nombre);
				S=S->Siguiente;
			}
		}

		void TirarBombaAtomica(int indice)
		{
			//Liquida lo que haya en IwoJima y Okinawa.
			int i=0;
			Estacion^ Candidato=nullptr;
			Estacion^ P= PTREstacion;
			while(i!=indice)
			{
				i++;
				Candidato=P;
				P=P->SgtEst;
			}
			if(P==PTREstacion)
			{
				PTREstacion=PTREstacion->SgtEst;
			}
			else
			{
				Candidato->SgtEst=P->SgtEst;
			}
			delete(P);
		}

		void Torpedo(int indice1, int indice2)
		{
			//Elimina un barco de la flota Japonesa
			int i=0;
			Estacion^ P= PTREstacion;
			while(i!=indice1)
			{
				i++;
				P=P->SgtEst;
			}
			i=0;
			Barco^ Senuelo=nullptr;
			Barco^ Blanco=P->Cola;
			while(i!=indice2)
			{
				i++;
				Senuelo=Blanco;
				Blanco=Blanco->Siguiente;
			}
			if(Blanco==P->Cola)
			{
				P->Cola=Blanco->Siguiente;
			}
			else
			{
				Senuelo->Siguiente=Blanco->Siguiente;
			}
			delete(Blanco);
		}

		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(119, 71);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Do Magic!";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(12, 131);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(120, 95);
			this->listBox1->TabIndex = 1;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::MuestraLosBarcos);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->checkBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 100);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Ingreso de Datos";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(6, 45);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(131, 17);
			this->checkBox1->TabIndex = 2;
			this->checkBox1->Text = L"Ingreso de Estaciones";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(62, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Información";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(74, 19);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(120, 20);
			this->textBox1->TabIndex = 0;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 115);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(59, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Estaciones";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(139, 115);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(40, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Barcos";
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->Location = System::Drawing::Point(142, 132);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(120, 95);
			this->listBox2->TabIndex = 5;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button2);
			this->groupBox2->Controls->Add(this->radioButton2);
			this->groupBox2->Controls->Add(this->radioButton1);
			this->groupBox2->Location = System::Drawing::Point(219, 13);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(124, 100);
			this->groupBox2->TabIndex = 6;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Aniquilación";
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(7, 16);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(102, 17);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->Text = L"Huracan Katrina";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Checked = true;
			this->radioButton2->Location = System::Drawing::Point(7, 40);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(98, 17);
			this->radioButton2->TabIndex = 1;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Nigga Bazooca";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(7, 71);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(111, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Avada Kedavra";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(355, 273);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->listBox1);
			this->Name = L"Form1";
			this->Text = L"USMC";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 if(checkBox1->Checked)
				 {
					CrearEstacion(textBox1->Text);
					MostrarEstaciones();
				 }
				 else
				 {
					 int index = listBox1->SelectedIndex;
					 if(index!=-1)
					 {
						 AgregarBarco(index,textBox1->Text);
						 MostrarFlota(index);
					 }
					 else
					 {
						 MessageBox::Show("Seleccione una estacion primero");
					 }
				 }
			 }
private: System::Void MuestraLosBarcos(System::Object^  sender, System::EventArgs^  e) {
			int index = listBox1->SelectedIndex;
			if(index!=-1)
			{
				MostrarFlota(index);
			}
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 //Ver Pearl Harbor
			 int Muelle = listBox1->SelectedIndex;
			 int flotilla=listBox2->SelectedIndex;
			 listBox1->Items->Clear();
			 listBox2->Items->Clear();
			 if(radioButton2->Checked)
			 {
				Torpedo(Muelle,flotilla);
				MostrarEstaciones();
				MostrarFlota(flotilla);
			 }
			 else
			 {
				 TirarBombaAtomica(Muelle);
				 MostrarEstaciones();
			 }
		 }
};
}

