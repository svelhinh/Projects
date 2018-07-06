08048464 <verify_user_name>:
 8048464:       55                      push   ebp
 8048465:       89 e5                   mov    ebp,esp
 8048467:       57                      push   edi
 8048468:       56                      push   esi
 8048469:       83 ec 10                sub    esp,0x10
 804846c:       c7 04 24 90 86 04 08    mov    DWORD PTR [esp],0x8048690
 8048473:       e8 08 ff ff ff          call   8048380 <puts@plt>
 8048478:       ba 40 a0 04 08          mov    edx,0x804a040
 804847d:       b8 a8 86 04 08          mov    eax,0x80486a8
 8048482:       b9 07 00 00 00          mov    ecx,0x7
 8048487:       89 d6                   mov    esi,edx
 8048489:       89 c7                   mov    edi,eax
 804848b:       f3 a6                   repz cmps BYTE PTR ds:[esi],BYTE PTR es:[edi]
 804848d:       0f 97 c2                seta   dl
 8048490:       0f 92 c0                setb   al
 8048493:       89 d1                   mov    ecx,edx
 8048495:       28 c1                   sub    cl,al
 8048497:       89 c8                   mov    eax,ecx
 8048499:       0f be c0                movsx  eax,al
 804849c:       83 c4 10                add    esp,0x10
 804849f:       5e                      pop    esi
 80484a0:       5f                      pop    edi
 80484a1:       5d                      pop    ebp
 80484a2:       c3                      ret

080484a3 <verify_user_pass>:
 80484a3:       55                      push   ebp
 80484a4:       89 e5                   mov    ebp,esp
 80484a6:       57                      push   edi
 80484a7:       56                      push   esi
 80484a8:       8b 45 08                mov    eax,DWORD PTR [ebp+0x8]
 80484ab:       89 c2                   mov    edx,eax
 80484ad:       b8 b0 86 04 08          mov    eax,0x80486b0
 80484b2:       b9 05 00 00 00          mov    ecx,0x5
 80484b7:       89 d6                   mov    esi,edx
 80484b9:       89 c7                   mov    edi,eax
 80484bb:       f3 a6                   repz cmps BYTE PTR ds:[esi],BYTE PTR es:[edi]
 80484bd:       0f 97 c2                seta   dl
 80484c0:       0f 92 c0                setb   al
 80484c3:       89 d1                   mov    ecx,edx
 80484c5:       28 c1                   sub    cl,al
 80484c7:       89 c8                   mov    eax,ecx
 80484c9:       0f be c0                movsx  eax,al
 80484cc:       5e                      pop    esi
 80484cd:       5f                      pop    edi
 80484ce:       5d                      pop    ebp
 80484cf:       c3                      ret

080484d0 <main>:
 80484d0:       55                      push   ebp
 80484d1:       89 e5                   mov    ebp,esp
 80484d3:       57                      push   edi
 80484d4:       53                      push   ebx
 80484d5:       83 e4 f0                and    esp,0xfffffff0
 80484d8:       83 ec 60                sub    esp,0x60
 80484db:       8d 5c 24 1c             lea    ebx,[esp+0x1c]
 80484df:       b8 00 00 00 00          mov    eax,0x0
 80484e4:       ba 10 00 00 00          mov    edx,0x10
 80484e9:       89 df                   mov    edi,ebx
 80484eb:       89 d1                   mov    ecx,edx
 80484ed:       f3 ab                   rep stos DWORD PTR es:[edi],eax
 80484ef:       c7 44 24 5c 00 00 00    mov    DWORD PTR [esp+0x5c],0x0
 80484f6:       00
 80484f7:       c7 04 24 b8 86 04 08    mov    DWORD PTR [esp],0x80486b8
 80484fe:       e8 7d fe ff ff          call   8048380 <puts@plt>
 8048503:       b8 df 86 04 08          mov    eax,0x80486df
 8048508:       89 04 24                mov    DWORD PTR [esp],eax
 804850b:       e8 50 fe ff ff          call   8048360 <printf@plt>
 8048510:       a1 20 a0 04 08          mov    eax,ds:0x804a020
 8048515:       89 44 24 08             mov    DWORD PTR [esp+0x8],eax
 8048519:       c7 44 24 04 00 01 00    mov    DWORD PTR [esp+0x4],0x100
 8048520:       00
 8048521:       c7 04 24 40 a0 04 08    mov    DWORD PTR [esp],0x804a040
 8048528:       e8 43 fe ff ff          call   8048370 <fgets@plt>
 804852d:       e8 32 ff ff ff          call   8048464 <verify_user_name>
 8048532:       89 44 24 5c             mov    DWORD PTR [esp+0x5c],eax
 8048536:       83 7c 24 5c 00          cmp    DWORD PTR [esp+0x5c],0x0
 804853b:       74 13                   je     8048550 <main+0x80>
 804853d:       c7 04 24 f0 86 04 08    mov    DWORD PTR [esp],0x80486f0
 8048544:       e8 37 fe ff ff          call   8048380 <puts@plt>
 8048549:       b8 01 00 00 00          mov    eax,0x1
 804854e:       eb 5f                   jmp    80485af <main+0xdf>
 8048550:       c7 04 24 0d 87 04 08    mov    DWORD PTR [esp],0x804870d
 8048557:       e8 24 fe ff ff          call   8048380 <puts@plt>
 804855c:       a1 20 a0 04 08          mov    eax,ds:0x804a020
 8048561:       89 44 24 08             mov    DWORD PTR [esp+0x8],eax
 8048565:       c7 44 24 04 64 00 00    mov    DWORD PTR [esp+0x4],0x64
 804856c:       00
 804856d:       8d 44 24 1c             lea    eax,[esp+0x1c]
 8048571:       89 04 24                mov    DWORD PTR [esp],eax
 8048574:       e8 f7 fd ff ff          call   8048370 <fgets@plt>
 8048579:       8d 44 24 1c             lea    eax,[esp+0x1c]
 804857d:       89 04 24                mov    DWORD PTR [esp],eax
 8048580:       e8 1e ff ff ff          call   80484a3 <verify_user_pass>
 8048585:       89 44 24 5c             mov    DWORD PTR [esp+0x5c],eax
 8048589:       83 7c 24 5c 00          cmp    DWORD PTR [esp+0x5c],0x0
 804858e:       74 07                   je     8048597 <main+0xc7>
 8048590:       83 7c 24 5c 00          cmp    DWORD PTR [esp+0x5c],0x0
 8048595:       74 13                   je     80485aa <main+0xda>
 8048597:       c7 04 24 1e 87 04 08    mov    DWORD PTR [esp],0x804871e
 804859e:       e8 dd fd ff ff          call   8048380 <puts@plt>
 80485a3:       b8 01 00 00 00          mov    eax,0x1
 80485a8:       eb 05                   jmp    80485af <main+0xdf>
 80485aa:       b8 00 00 00 00          mov    eax,0x0
 80485af:       8d 65 f8                lea    esp,[ebp-0x8]
 80485b2:       5b                      pop    ebx
 80485b3:       5f                      pop    edi
 80485b4:       5d                      pop    ebp
 80485b5:       c3                      ret


0x804a040 <a_user_name>
SHELLCODE : 0xffffd8c7