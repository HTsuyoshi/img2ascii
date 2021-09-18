if __name__ == '__main__':
    with open('braille_data', 'r') as f:
        save = open('braille_data.h', 'w')
        save.write('char16_t braille_data[256] = {\n')
        for line in f.read().split('\n'):
            try:
                save.write(f'U"{hex(int(line))[2:]}",\n')
            except:
                print('Last line error')
        save.write('};')
