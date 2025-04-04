function [image1, image2, output] = Assignment3()
%Read two images and add them over eachother
image1 = imread("cameraman.tif");
image2 = imread("rice.png");

sub_image1 = image1(1:256, 1:256);
sub_image2 = image2(1:256, 1:256);

output = sub_image2 + sub_image1;

subplot(1,3,1), imshow(sub_image1);
subplot(1,3,2), imshow(sub_image2);
subplot(1,3,3), imshow(output);
end