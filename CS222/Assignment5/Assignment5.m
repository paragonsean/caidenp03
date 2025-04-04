image1 = imread("text.png");
subplot(2,2,1), imshow(image1), title('Original image');
output1 = image1>85;
subplot(2,2,2), imshow(output1), title('Image after thresholding');
image2 = imread("paperclips.jpg");
subplot(2,2,3), imshow(image2), title('Original image');
output2 = image2>135;
subplot(2,2,4), imshow(output2), title('Image after thresholding');