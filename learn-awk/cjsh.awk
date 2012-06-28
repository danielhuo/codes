# bailing, 2009/07/21
# cheng ji si han

BEGIN{ 
    FS = "," 
}

NF==3 { arr_click[$1] += 1 }
NF==4 {
    if(index(FILENAME, "active") == 1){
        arr_active[$1] += 1
    }
    else if(index(FILENAME, "reg") == 1){
        arr_reg[$1] += 1
    }
    else if(index(FILENAME, "down") == 1){
        arr_download[$1] += 1

        if(arr_download_uip[$1,$4] != 1){
            arr_download_uip[$1,$4] = 1
            arr_download_unique_ip[$1] += 1
        }
    }
}

END{
    sidx = match(FILENAME, "2")     # filename format: xxx_xxx_20090721.log
    dt = substr(FILENAME,sidx,8)    # get date str

    ofname = sprintf("result_statistics_%s.log", dt)

    for(item in arr_click){
        ad_id = item    

        click_num = arr_click[ad_id]
        reg_num = 0
        active_num = 0
        download_num = 0
        download_num_unique = 0

        if(ad_id in arr_active){
            active_num = arr_active[ad_id]    
        }
        if(ad_id in arr_reg){
            reg_num = arr_reg[ad_id]    
        }
        if(ad_id in arr_download){
            download_num = arr_download[ad_id]    
        }
        if(ad_id in arr_download_unique_ip){
            download_num_unique = arr_download_unique_ip[ad_id]
        }

        if(ad_id == "") ad_id = "0"
        printf("%s,%s,%d,%d,%d,%d,%d\n", 
                  dt, ad_id, click_num, reg_num, active_num, download_num, download_num_unique) > ofname
    }
}

