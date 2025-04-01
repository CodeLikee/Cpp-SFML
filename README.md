<h1>SFML : </h1>


<h2>For every project you have to repeat these steps: </h2>
<ol>
  <li>Select an empty project in Visual Sudio and press next.</li>
  <li>Give name and choose the location for that project, press create.</li>
  <li>Create a c++ file first.</li>
  <li>Go to Project and then project properties.</li>
  <li>Select <b>configuration</b> to <b>All Configuration</b></li>
  
  <li>Go to Debugging ➡️ Environment : </br><pre>PATH=D:\User\SFML-2.6.1\bin</pre>Click on Apply.</li>
  
  <li>Go to C/C++ then General then Additional Include Directories :<pre>D:\User\SFML-2.6.1\include </pre>Click on Apply.</li>
  
  <li>Go to Linker ➡️ General ➡️> Additional Library Directories :<pre>D:\User\SFML-2.6.1\lib </pre>Click on Apply.</li>
  
  <li>Select <b>configuration</b> to <b>Debug.</b></li>
  
  <li>Go to Input ➡️ Additional Dependencies ➡️ edit :<pre>sfml-graphics-d.lib
sfml-window-d.lib
sfml-audio-d.lib
sfml-network-d.lib
sfml-system-d.lib
</pre>Click on Apply.</li>
  <li>Select <b>configuration</b> to <b>Release.</b></li>
  <li>Go to Input ➡️ Additional Dependencies ➡️ edit :<pre>sfml-graphics.lib
sfml-window.lib
sfml-audio.lib
sfml-network.lib
sfml-system.lib
</pre>click on apply and Ok.</li>
  <li>Now 😎 are ready to work 👍</li>
</ol>
