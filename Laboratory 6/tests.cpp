#include "DynamicVector.h"
#include "Victim.h"
#include "Repository.h"
#include "Service.h"

#include <assert.h>
#include "tests.h"

//Tests for DynamicArray

void AddElementToDynamicArray_ValidInput_AddedToList() {
	DynamicVector<Victim> dynamicVector;
	Victim victim = Victim("ana");
	dynamicVector.addElement(victim);
	assert(dynamicVector.getSize() == 1);
}

void DeleteElementToDynamicArray_ValidInput_DeletedFromList() {
	DynamicVector<Victim> dynamicVector;
	Victim victim = Victim("ana");
	dynamicVector.addElement(victim);
	dynamicVector.deleteElement(victim);
	assert(dynamicVector.getSize() == 0);
}

void UpdateElementToDynamicArray_ValidInput_DeletedFromList() {
	DynamicVector<Victim> dynamicVector;
	Victim victim = Victim("ana", "cluj", 50, "link");
	Victim victim2 = Victim("ana", "alba", 40, "linnk2");
	dynamicVector.addElement(victim);
	dynamicVector.updateElement(victim2);
	assert(dynamicVector.getElementOnPosition(0).getPlaceOfOrigin().compare("alba") == 0);
}

void ExistElementInDynamicArray_ExistingInput_ReturnedTrue() {
	DynamicVector<Victim> dynamicVector;
	Victim victim = Victim("ana", "cluj", 50, "link");
	dynamicVector.addElement(victim);
	assert(dynamicVector.existElement(victim) == true);
}

void ExistElementInDynamicArray_NonexistingInput_ReturnedFalse() {
	DynamicVector<Victim> dynamicVector;
	Victim victim = Victim("ana", "cluj", 50, "link");
	assert(dynamicVector.existElement(victim) == false);
}

//Domain = Victim
void GetNameOfAVictim_ExistingInput_ReturnedString() {
	Victim victim = Victim("ana", "cluj", 50, "link");
	assert(victim.getName().compare("ana") == 0);
}

void GetPlaceOfOriginOfAVictim_ExistingInput_ReturnedString() {
	Victim victim = Victim("ana", "cluj", 50, "link");
	assert(victim.getPlaceOfOrigin().compare("cluj") == 0);
}

void GetAgeOfAVictim_ExistingInput_ReturnedInt() {
	Victim victim = Victim("ana", "cluj", 50, "link");
	assert(victim.getAge() == 50);
}

void GetPhotoLinkOfAVictim_ExistingInput_ReturnedString() {
	Victim victim = Victim("ana", "cluj", 50, "link");
	assert(victim.getPhotoLink().compare("link") == 0);
}

//Test Repository
void AddVictimToRepo_ValidInput_AddedToRepo() {
	Victim victim = Victim("ana", "cluj", 50, "link");
	Repository repo = {};
	repo.addVictim(victim);
	assert(repo.getAllVictims().getSize() == 1);
}

void AddVictimToRepo_InvalidInput_NotAddedToRepo() {
	Victim victim = Victim("ana", "cluj", 50, "link");
	Repository repo = {};
	repo.addVictim(victim);
	try {
		repo.addVictim(victim);
		assert(false);
	}
	catch (std::exception) {
		assert(true);
	}
}

void DeleteVictimFromRepo_ValidInput_DeletedFromRepo() {
	Victim victim = Victim("ana", "cluj", 50, "link");
	Repository repo = {};
	repo.addVictim(victim);
	repo.deleteVictim(victim);
	assert(repo.getAllVictims().getSize() == 0);
}

void DeleteVictimFromRepo_InvalidInput_NotDeletedFromRepo() {
	Victim victim = Victim("ana", "cluj", 50, "link");
	Victim victim2 = Victim("maria", "alba", 25, "link2");
	Repository repo = {};
	repo.addVictim(victim);
	try {

		repo.deleteVictim(victim2);
		assert(false);
	}
	catch (std::exception) {
		assert(true);
	}
}

void UpdateVictimFromRepo_ValidInput_UpdatedInRepo() {
	Victim victim = Victim("maria", "cluj", 50, "link");
	Victim victim2 = Victim("maria", "alba", 25, "link2");
	Repository repo = {};
	repo.addVictim(victim);
	repo.updateVictim(victim2);
	assert(repo.getAllVictims().getElementOnPosition(0).getAge() == 25);
}

void UpdateVictimFromRepo_InvalidInput_NotUpdatedInRepo() {
	Victim victim2 = Victim("maria", "alba", 25, "link2");
	Repository repo = {};
	try {
		repo.updateVictim(victim2);
		assert(false);
	}
	catch (std::exception) {
		assert(true);
	}
}

void GetNextVictimFromRepo_ValidInput_ReturnedTheVictim() {
	Victim victim = Victim("maria", "cluj", 50, "link");
	Victim victim2;
	Repository repo = {};
	repo.addVictim(victim);
	victim2 = repo.getNextFile();
	assert(victim == victim2);
}

void AddVictimToAssistantFile_ValidInput_AddedToAssistantRepo() {
	Victim victim = Victim("maria", "cluj", 50, "link");
	Victim victim2 = Victim("ana", "alba", 25, "link2");
	Repository repo = {};
	repo.addVictim(victim);
	repo.addVictim(victim2);
	repo.addVictimToAssistantFile(victim);
	DynamicVector<Victim> savedFiles = repo.getAllAssistantSavedFiles();
	assert(savedFiles.getSize() == 1);
}

void AddVictimToAssistantFile_InvalidInput_NotAddedToAssistantRepo() {
	Victim victim = Victim("maria", "cluj", 50, "link");
	Victim victim2 = Victim("ana", "alba", 25, "link2");
	Repository repo = {};
	repo.addVictim(victim);
	repo.addVictimToAssistantFile(victim2);
	DynamicVector<Victim> savedFiles = repo.getAllAssistantSavedFiles();
	assert(savedFiles.getSize() == 0);
}

//Tests Service

void AddVictimToService_ValidInput_AddedToService() {
	Repository repo = {};
	Service service = { repo };
	Victim victim2 = Victim("maria", "alba", 25, "link2");
	service.addVictim("maria", "alba", 25, "link2");
	assert(service.getAllVictims().getElementOnPosition(0).getName().compare("maria") == 0);
}

void AddVictimToService_InvalidInput_NotAddedToService() {
	Repository repo = {};
	Service service = { repo };
	Victim victim2 = Victim("maria", "alba", 25, "link2");
	service.addVictim("maria", "alba", 25, "link2");
	try {
		service.addVictim("maria", "alba", 25, "link2");
		assert(false);
	}
	catch (std::exception) {
		assert(true);
	}
}

void DeleteVictimFromService_ValidInput_DeletedFromService() {
	Repository repo = {};
	Service service = { repo };
	Victim victim2 = Victim("maria", "alba", 25, "link2");
	service.addVictim("maria", "alba", 25, "link2");
	service.deleteVictim("maria");
	assert(service.getAllVictims().getSize() == 0);
}

void DeleteVictimFromService_InvalidInput_NotDeletedFromService() {
	Repository repo = {};
	Service service = { repo };
	Victim victim2 = Victim("maria", "alba", 25, "link2");
	service.addVictim("maria", "alba", 25, "link2");
	try {
		service.deleteVictim("ana");
		assert(false);
	}
	catch (std::exception) {
		assert(true);
	}
}

void UpdateVictimFromService_ValidInput_UpdatedInService() {
	Repository repo = {};
	Service service = { repo };
	service.addVictim("maria", "alba", 25, "link2");
	service.updateVictim("maria", "cluj", 30, "link");
	assert(service.getAllVictims().getElementOnPosition(0).getPlaceOfOrigin().compare("cluj") == 0);
}

void UpdateVictimFromService_InvalidInput_NotUpdatedInService() {
	Repository repo = {};
	Service service = { repo };
	service.addVictim("maria", "alba", 25, "link2");
	try {
		service.updateVictim("ana", "cluj", 30, "link");
		assert(false);
	}
	catch (std::exception) {
		assert(true);
	}
}

void GetNextVictimFromAssistantRepositoryService_ValidInput_ReturnedVictim() {
	Repository repo = {};
	Service service = { repo };
	service.addVictim("maria", "alba", 25, "link2");
	assert(service.getTheNextFile().getName() == "maria");
}

void AddVictimToAssistantRepoService_ValidInput_AddedToRepo() {
	Repository repo = {};
	Service service = { repo };
	service.addVictim("maria", "alba", 25, "link2");
	service.saveVictimToAssistantListOfVictims("maria");
	DynamicVector<Victim> savedFiles = service.getTheAssistantListOfVictims();
	assert(savedFiles.getSize() == 1);
}

void AddVictimToAssistantRepoService_InvalidInput_AddedToRepo() {
	Repository repo = {};
	Service service = { repo };
	service.addVictim("maria", "alba", 25, "link2");
	service.saveVictimToAssistantListOfVictims("ana");
	DynamicVector<Victim> savedFiles = service.getTheAssistantListOfVictims();
	assert(savedFiles.getSize() == 0);
}

void GetFilteredFilesFromAssistantRepoService_ValidInput_ReturnedVictims() {
	Repository repo = {};
	Service service = { repo };
	service.addVictim("maria", "alba", 25, "link2");
	service.addVictim("ana", "alba", 35, "link2");
	DynamicVector<Victim> savedFiles = service.getFiteredListOfVictimFiles("alba", 30);
	assert(savedFiles.getSize() == 1);
}

void testAll() {
	AddElementToDynamicArray_ValidInput_AddedToList();
	DeleteElementToDynamicArray_ValidInput_DeletedFromList();
	UpdateElementToDynamicArray_ValidInput_DeletedFromList();
	ExistElementInDynamicArray_ExistingInput_ReturnedTrue();
	ExistElementInDynamicArray_NonexistingInput_ReturnedFalse();
	GetNextVictimFromRepo_ValidInput_ReturnedTheVictim();
	AddVictimToAssistantFile_ValidInput_AddedToAssistantRepo(); 

	GetNameOfAVictim_ExistingInput_ReturnedString();
	GetPlaceOfOriginOfAVictim_ExistingInput_ReturnedString();
	GetAgeOfAVictim_ExistingInput_ReturnedInt();
	GetPhotoLinkOfAVictim_ExistingInput_ReturnedString();

	AddVictimToRepo_ValidInput_AddedToRepo();
	DeleteVictimFromRepo_ValidInput_DeletedFromRepo();
	UpdateVictimFromRepo_ValidInput_UpdatedInRepo();

	AddVictimToService_ValidInput_AddedToService();
	AddVictimToService_InvalidInput_NotAddedToService();
	DeleteVictimFromService_ValidInput_DeletedFromService();
	DeleteVictimFromService_InvalidInput_NotDeletedFromService();
	UpdateVictimFromService_ValidInput_UpdatedInService();
	UpdateVictimFromService_InvalidInput_NotUpdatedInService();
	GetNextVictimFromAssistantRepositoryService_ValidInput_ReturnedVictim();
	AddVictimToAssistantRepoService_ValidInput_AddedToRepo();
	AddVictimToAssistantRepoService_InvalidInput_AddedToRepo();
	GetFilteredFilesFromAssistantRepoService_ValidInput_ReturnedVictims();
}