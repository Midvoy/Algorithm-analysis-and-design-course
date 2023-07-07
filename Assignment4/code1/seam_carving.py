import numpy as np
import cv2

def calc_energy_map(image):
    b, g, r = cv2.split(image)
    b_energy = np.absolute(cv2.Scharr(b, -1, 1, 0)) + np.absolute(cv2.Scharr(b, -1, 0, 1))
    g_energy = np.absolute(cv2.Scharr(g, -1, 1, 0)) + np.absolute(cv2.Scharr(g, -1, 0, 1))
    r_energy = np.absolute(cv2.Scharr(r, -1, 1, 0)) + np.absolute(cv2.Scharr(r, -1, 0, 1))
    return b_energy + g_energy + r_energy


def seam_carving(image,scale):

    out_image=np.copy(image)
    out_width=int(image.shape[1]*scale) #取整

    for progress in range(0,image.shape[1]-out_width):
        print(progress,'/',image.shape[1]-out_width)  #进度
        energy_map=calc_energy_map(out_image) #得到能量图

        # 初始化dp数组
        row=out_image.shape[0]
        col=out_image.shape[1]
        dp=np.zeros((row, col))
        path=np.zeros((row, col))
        dp[0]=energy_map[0]

        #dp
        for i in range(1, row):
            for j in range(0, col):
                min_energy=dp[i-1][j]
                path[i][j]=j
                if(j-1>=0):
                    if(min_energy>dp[i-1][j-1]):
                        min_energy=dp[i-1][j-1]
                        path[i][j]=j-1
                if(j+1<col):
                    if(min_energy>dp[i-1][j+1]):
                        min_energy=dp[i-1][j+1]#
                        path[i][j]=j+1
                dp[i][j]=energy_map[i][j]+min_energy
                
        #回溯找seam
        seam=np.zeros(row)
        min_energy=dp[row-1][0]
        min_col=0
        for j in range(1,col):
            if(min_energy>dp[row-1][j]):
                min_energy=dp[row-1][j]
                min_col=j
        seam[row-1]=min_col
        for i in range(row-1,0,-1):
            min_col=int(path[i][min_col])
            seam[i-1]=min_col

        #删除seam
        for i in range(0,row):  
            del_col = int(seam[i])
            for j in range(del_col,col-1):
                out_image[i][j]=out_image[i][j+1]
        out_image=np.delete(out_image,col-1,1)
    return out_image

