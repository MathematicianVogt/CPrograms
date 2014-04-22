// vault-stub.c starts the implementation of vault.c
#include <stdio.h>
#include <stdlib.h>

#include "vault.h"
#include "file_tools.h"

/// open the vault file.
int v_open( const char * filename ) {

	return 0;
}

/// close the vault file.
int v_close( Vault vid ) {

	return 0;
}

/// create an entry for the vault.
VaultEntry_T * v_create( char * title, char * artist, int value, int cost ) {

	return NULL;
}

/// add an entry to the vault file.
int v_add( Vault vid, VaultEntry_T * entry ) {

	return 0;
}

/// get the entry at the index.
VaultEntry_T * v_get( Vault vid, size_t index ) {

	return NULL;
}

/// update the entry at the index with new information.
int v_update( Vault vid, size_t index, VaultEntry_T * entry ) {

	return 0;
}

/// delete the entry at the index, replacing it with the last entry's content.
int v_delete( Vault vid, size_t index ) {

	return 0;
}

/// return the number of entries in the vault file.
size_t v_size( Vault vid ) {

	return 0;
}

/// get the index associated with the current file offset into the vault.
size_t v_index( Vault vid ) {

	return 0;
}

/// set the file offset so it refers to the index-th record in the vault file.
size_t v_set_index( Vault vid, size_t index ) {

	return 0;
}

/// print the entry.
void v_print_entry( VaultEntry_T * entry ) {

	return ;
}

// end file
