import subprocess
import re
import csv

def get_pg_osd_mapping(pool_name, output_file):
    # 执行 ceph pg ls-by-pool 命令并获取输出
    cmd = f'bin/ceph pg ls-by-pool {pool_name}'
    result = subprocess.run(cmd.split(), capture_output=True, text=True)
    
    if result.returncode != 0:
        print(f"Error running command: {result.stderr}")
        return
    
    # 使用正则表达式匹配PG和OSD列表
    pattern = r"(\d+\.\w+)\s.*\s\[(.*?)\]"
    matches = re.findall(pattern, result.stdout)
    
    if not matches:
        print(f"No PGs found for pool {pool_name}")
        return
    
    # 创建PG到OSD映射的字典
    pg_osd_map = {}
    
    for pg, osds in matches:
        osd_list = osds.split(',')
        pg_osd_map[pg] = osd_list  # 将pg作为键，osd列表作为值
        print(f"PG: {pg}, OSDs: {osds}")
    
    # 保存到CSV文件
    with open(output_file, mode='w', newline='') as csvfile:
        csv_writer = csv.writer(csvfile)
        csv_writer.writerow(['PG', 'Mapped OSDs'])
        
        for pg, osds in pg_osd_map.items():
            csv_writer.writerow([pg, ', '.join(osds)])
    
    print(f"PG to OSD mapping saved to {output_file}")
    
    # 返回生成的PG到OSD映射字典
    return pg_osd_map

# 调用示例
pool_name = "mypool"
output_file = "pg_osd_mapping.csv"
pg_osd_mapping = get_pg_osd_mapping(pool_name, output_file)

# 打印生成的映射
if pg_osd_mapping:
    print("\nGenerated PG to OSD mapping:")
    for pg, osds in pg_osd_mapping.items():
        print(f"PG: {pg}, OSDs: {osds}")
