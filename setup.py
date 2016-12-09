from distutils.core import setup, Extension

module1 = Extension('handsome',
                    sources = ['src/handsome.c', 'src/md5.c'],
                    include_dirs = ['src/'],
                    library_dirs = ['src/'])

setup (name = 'handsome',
       version = '1.0',
       description = 'computer checkcode for qlcoder.com xishuashua',
       author = 'zlc1994',
       author_email = 'zhangliangchun1994@gmail.com',
       url ='https://github.com/zlc1994/xishuashuavote',
       ext_modules = [module1])
