#pragma region region1
//
//
//// create the value to store vertex shader in
//GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
//// Attach Vertex Shader source to the Vertex Shader Object
//glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//// Compile the Vertex Shader into machine code
//glCompileShader(vertexShader);
//
//// Create Fragment Shader Object and get its reference
//GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//// Attach Fragment Shader source to the Fragment Shader Object
//glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//glCompileShader(fragmentShader);
//
//// Create Shader Program Object and get its reference
//GLuint shaderProgram = glCreateProgram();
//// Attach the Vertex and Fragment Shaders to the Shader Program
//glAttachShader(shaderProgram, vertexShader);
//glAttachShader(shaderProgram, fragmentShader);
//// wrap up the shader program
//// pass it in the shader program reference
//glLinkProgram(shaderProgram);
//
//// delete the shader created before bcs they're already in the program itself
//glDeleteShader(vertexShader);
//glDeleteShader(fragmentShader);
//
//
//
//
///* send stuff between CPUand GPU is slow
//* -> send it into big batches (big batches = buffers)
//*/
//
//// VBO is an array of references
//GLuint VAO, VBO, EBO;    // one object -> need one
//
//// create buffers object, give it 1 as first argument
//// because have only one 3D object and point it to the reference
//// 
//// VAO: vertex Array Object -> wuickly be able to switch between different VBOs
//// VBO: vertex Buffer Object
//glGenVertexArrays(1, &VAO); // MUST GENERATE BEFORE - VBO
//glGenBuffers(1, &VBO);
//glGenBuffers(1, &EBO);
//
//// find the VAO -> can work with it
//glBindVertexArray(VAO);
//
///* binding
//* make a certain object - the current object
//* whenever fire a function that would modify that type of object
//* -> modify the current object - aka the binded object
//*/
//glBindBuffer(GL_ARRAY_BUFFER, VBO);
//
//// store vertices in the VBO
//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//
//// specify the type of element
//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//// link indices array
//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//
//// config for openGL to know how to read VBO
//
//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//glEnableVertexAttribArray(0);
//
//// make sure won't change a VBA or VBO
//// combine both VBO and VAO -> binding to 0
//glBindBuffer(GL_ARRAY_BUFFER, 0);
//glBindVertexArray(0);
//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
//
//
////// specify the color of the background
////glClearColor(0.07f, 0.13f, 0.17f, 1.9f);
////// clean the back buffer and assign the neaw color
////glClear(GL_COLOR_BUFFER_BIT);
////// clean the back buffer with the front buffer
////glfwSwapBuffers(window);
//
//// unbind EBO after VAO
//
//
#pragma endregion



#pragma region region2
//
//glDeleteVertexArrays(1, &VAO);
//glDeleteBuffers(1, &VBO);
//glDeleteBuffers(1, &EBO);
//glDeleteProgram(shaderProgram);
//
#pragma endregion



#pragma region region3
//
//- 0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
//0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
//0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f, // Upper corner
//-0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner left
//0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner right
//0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f // Inner down
//
//
#pragma endregion
