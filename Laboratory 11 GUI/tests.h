#pragma once

void testAll();


void GetNameOfAVictim_ExistingInput_ReturnedString();
void GetPlaceOfOriginOfAVictim_ExistingInput_ReturnedString();
void GetAgeOfAVictim_ExistingInput_ReturnedInt();
void GetPhotoLinkOfAVictim_ExistingInput_ReturnedString();
void GetStringOfVictim_ValidInput_ReturnString();


void AddVictimToRepo_ValidInput_AddedToRepo();
void AddVictimToRepo_InvalidInput_NotAddedToRepo();
void DeleteVictimFromRepo_ValidInput_DeletedFromRepo();
void DeleteVictimFromRepo_InvalidInput_NotDeletedFromRepo();
void UpdateVictimFromRepo_ValidInput_UpdatedInRepo();
void GetNextVictimFromRepo_ValidInput_ReturnedTheVictim();
void AddVictimToAssistantFile_ValidInput_AddedToAssistantRepo();
void CheckVictimInAssistantFile_ValidInput_ReturnTrue();
void CheckVictimInAssistantFile_InvalidInput_ReturnFalse();
void CheckNextVictimInAssistantFile_ValidInput_ReturnValue();

void AddVictimToService_ValidInput_AddedToService();
void AddVictimToService_InvalidInput_NotAddedToService();
void DeleteVictimFromService_ValidInput_DeletedFromService();
void DeleteVictimFromService_InvalidInput_NotDeletedFromService();
void UpdateVictimFromService_ValidInput_UpdatedInService();
void UpdateVictimFromService_InvalidInput_NotUpdatedInService();
void GetNextVictimFromAssistantRepositoryService_ValidInput_ReturnedVictim();
void AddVictimToAssistantRepoService_ValidInput_AddedToRepo();
void AddVictimToAssistantRepoService_InvalidInput_AddedToRepo();
void GetFilteredFilesFromAssistantRepoService_ValidInput_ReturnedVictims();
void GetFilteredFilesFromAssistantRepoService_InvalidInput_ReturnedAllVictims();
