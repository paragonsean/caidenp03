image = imread("coins.png");
subplot(1,3,1), imshow(image);
filter = fspecial("laplacian");
filter2 = fspecial("average");

output1 = imfilter(image,filter);
subplot(1,3,2), imshow(output1);

output2 = imfilter(image,filter2);
subplot(1,3,3), imshow(output2);

    