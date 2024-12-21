# Handwriting-character-recognition-software
handwrite recognition software under KNN (simplified method) using C++ language
Steps

1.Generate a drawing board to manually draw characters on it. 
You can choose 
1a.export the drawn image as an image representing a certain number and convert it into dataset for machine training.
1b.export the drawn images and convert them into a test set for machine recognition testing;

2.Divide the boundaries of the drawn characters, accurately select the range containing characters in the drawing area, crop and scale them(normalizing)

3.Compare and count identical pixels,export the top ten characters with the highest similarity, also the percentage of identical pixels as accuracy
