/**
 * @class Release
 * @property {number} totalFiles - The total number of files in the release.
 * @property {boolean} isPrivate - Indicates whether the release is private or not.
 * @property {boolean} published - Indicates whether the release has been published or not.
 * @property {string} id - The unique identifier for the release.
 * @property {string} createdAt - The timestamp when the release was created.
 * @property {string} updatedAt - The timestamp when the release was last updated.
 * @property {string} name - The name of the release.
 * @property {string} channel - The channel for the release.
 * @property {string} version - The version of the release.
 * @property {string} notes - The release notes.
 * @property {string} publishedAt - The timestamp when the release was published.
 * @property {string} productId - The unique identifier for the product that this release is associated with.
 * @property {string[]} platforms - An array of platforms for the release.
 * @property {Object[]} files - An array of files associated with the release.
 * @property {number} files.size - The size of the file in bytes.
 * @property {number} files.downloads - The number of times the file has been downloaded.
 * @property {boolean} files.secured - Indicates whether the file is secured or not.
 * @property {string} files.id - The unique identifier for the file.
 * @property {string} files.name - The name of the file.
 * @property {string} files.url - The URL of the file.
 * @property {string} files.extension - The file extension.
 * @property {string} files.checksum - The file checksum.
 * @property {string} files.releaseId - The unique identifier for the release that this file is associated with.
 * @property {string} files.createdAt - The timestamp when the file was created.
 * @property {string} files.updatedAt - The timestamp when the file was last updated.
 */
 
export class Release {
    totalFiles: number;
    isPrivate: boolean;
    published: boolean;
    id: string;
    createdAt: string;
    updatedAt: string;
    name: string;
    channel: string;
    version: string;
    notes: string;
    publishedAt: string;
    productId: string;
    platforms: string[];
    files: {
        size: number;
        downloads: number;
        secured: boolean;
        id: string;
        name: string;
        url: string;
        extension: string;
        checksum: string;
        releaseId: string;
        createdAt: string;
        updatedAt: string;
    }[];
};