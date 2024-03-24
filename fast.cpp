 ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

ios_base::sync_with_stdio(false); cin.tie(NULL);



#define faster                 \
  ios::sync_with_stdio(false); \
  cin.tie(nullptr);            \
  cout.tie(nullptr);

// write faster in code





// The lines you provided are used in C++ code and are related to input and output stream synchronization.

// 1. `ios::sync_with_stdio(false);`: By default, C++ synchronizes the C++ standard streams (such as `cin` and `cout`) with the C standard I/O functions (such as `scanf` and `printf`). This synchronization can add some overhead, and in certain cases, you might want to disable it for better performance. Setting `ios::sync_with_stdio(false);` turns off the synchronization.

// 2. `cin.tie(0);`: This line unties the cin stream from the cout stream. By default, the cin and cout streams are tied, meaning that when you perform input with `cin`, it automatically flushes the output buffer of `cout`. Untying them can sometimes improve performance by avoiding unnecessary flushes.

// 3. `cout.tie(0);`: This line unties the cout stream from any other stream. This is done to prevent cout from being automatically flushed whenever an input operation on cin occurs. Untying it can also improve performance by preventing unnecessary flushes.

// It's important to note that these optimizations are often micro-optimizations and may not have a significant impact on the performance of every program. In some cases, the default behavior might be sufficient, and manually disabling synchronization or untying streams may not be necessary. Additionally, the impact of these optimizations can vary depending on the specific use case and the compiler.
