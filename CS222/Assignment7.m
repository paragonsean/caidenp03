image = imread("coins.png");
output1 = nlfilter(image, [3,3], 'max(x(:))');
output2 = nlfilter(image, [3,3], 'min(x(:))');
output3 = imgaussfilt(image,4);
subplot(2,2,1), imshow(image)
subplot(2,2,2), imshow(output1)
subplot(2,2,3), imshow(output2)
subplot(2,2,4), imshow(output3)