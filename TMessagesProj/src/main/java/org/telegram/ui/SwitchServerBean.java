package org.telegram.ui;

import java.io.Serializable;

/**
 * @author Catherine Liu
 * 2021/10/19 11:56 上午
 * 切换服务端数据对象
 **/
public class SwitchServerBean implements Serializable {
    String name;
    String alias;
    String hostAddress;
    String hostName;

    public SwitchServerBean(String name,String alias, String hostName, String hostAddress) {
        this.name = name;
        this.alias = alias;
        this.hostAddress = hostAddress;
        this.hostName = hostName;
    }

}
